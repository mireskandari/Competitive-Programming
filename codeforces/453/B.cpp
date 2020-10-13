#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define err(a...) fprintf(stderr, a)
typedef long long ll;

bool Isp(int a) {
  for (int i = 2, sq = sqrt(a); i <= sq; ++i) {
    if (a % i == 0) return false;
  }
  return true;
}

bool Chmin(int &a, int b) {
  if (a < b) return false;
  a = b;
  return true;
}

constexpr int N = 110;

int a[N], b[N], nmsk[N], dp[1 << 18], new_dp[1 << 18];
pair<int, int> parent[N][1 << 18];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> primes;
  for (int i = 2; i <= 60; ++i) {
    if (Isp(i)) primes.push_back(i);
  }
  const int pn = primes.size();
  for (int i = 1; i <= 60; ++i) {
    for (int j = 0; j < pn; ++j) {
      if (i % primes[j] == 0) nmsk[i] ^= 1 << j;
    }
  }
  // 100 * 60 * 2^17
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    memset(new_dp, 0x3f, sizeof(new_dp));
    for (int msk = 0; msk < (1 << pn); ++msk) {
      for (int j = 1; j <= 60; ++j) {
        if (!(msk & nmsk[j]) && Chmin(new_dp[msk | nmsk[j]], dp[msk] + abs(a[i + 1] - j))) {
          parent[i + 1][msk | nmsk[j]] = {j, msk};
        }
      }
    }
    swap(dp, new_dp);
  }
  int best = -1;
  for (int msk = 0; msk < (1 << pn); ++msk) {
    if (best == -1 || dp[best] > dp[msk]) {
      best = msk;
    }
  }
  //err("%s", bitset<18>(best).to_string().c_str());
  for (int i = n; i > 0; --i) {
    b[i] = parent[i][best].first;
    if (i == 1) break;
    best = parent[i][best].second;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", b[i]);
  }
  return 0;
}