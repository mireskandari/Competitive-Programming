#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
#define V(...) vector<__VA_ARGS__>
#define PP(...) pair<__VA_ARGS__, __VA_ARGS__>
#define int ll

int constexpr MOD = 1e9 + 7;

int n, k;
ll dp[2010][2010];
V(int) dv[2010];

void norm(int &a) { // i dont like this :|
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  
  for (int i = 1; i <= n; i++) {
    for (ll j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        dv[i].emplace_back(j);
        if (i / j != j) {
          dv[i].emplace_back(i / j);
        }
      }
    }
  }
  
  for (int i = 1; i <= n; i++) dp[1][i] = 1;
  
  for (int i = 2; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      for (auto &d : dv[j]) {
        norm(dp[i][j] += dp[i - 1][d]);
      }
    }
  }

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    norm(sum += dp[k][i]);
  }

  cout << sum;
  return 0;
}
