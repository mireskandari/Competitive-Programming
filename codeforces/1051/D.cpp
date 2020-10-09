#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int M = 998244353;

// fuck there was a fucntion called std::norm
void okay(int &a) {
  if (a >= M) a -= M;
  if (a < 0) a += M;
}

constexpr int N = 3000;

inline int added(int new_mask, int mask) {
  if (mask == new_mask) return 0;
  if ((mask ^ new_mask) == (1 << 2) - 1) {
    if (__builtin_parity(new_mask)) return 2;
    return 1;
  }
  if (__builtin_parity(new_mask)) return 1;
  return 0;
}

int dp[1 << 2][N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  /*for (int mask = 0; mask < (1 << 2); ++mask) {
    for (int new_mask = 0; new_mask < (1 << 2); ++new_mask) {
      err("mask = %s new_mask = %s added = %d\n", bitset<2>(mask).to_string().c_str(), bitset<2>(new_mask).to_string().c_str(), added(new_mask, mask));
    }
  }*/
  for (int mask = 0; mask < (1 << 2); ++mask) {
    dp[mask][0][(int) __builtin_parity(mask) + 1] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int mask = 0; mask < (1 << 2); ++mask) {
        for (int new_mask = 0; new_mask < (1 << 2); ++new_mask) {
          if (j - added(new_mask, mask) >= 0) {
            okay(dp[new_mask][i][j] += dp[mask][i - 1][j - added(new_mask, mask)]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int mask = 0; mask < (1 << 2); ++mask) {
    okay(ans += dp[mask][n - 1][k]);
  }
  printf("%d", ans);
  return 0;
}
