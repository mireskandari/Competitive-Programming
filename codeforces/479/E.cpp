#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
#define V(...) vector<__VA_ARGS__>
#define PP(...) pair<__VA_ARGS__, __VA_ARGS__>

int constexpr N = 5010;
int constexpr MOD = 1e9 + 7;

inline ll norm(ll &a) { // :/
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
  return a;
}

int n, k, a, b;
ll dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> a >> b >> k;
  
  dp[0][a] = 1;
  for (int i = 0; i < k; i++) {
    V(ll) new_pref(n + 2);
    auto update = [&](int l, int r, ll val) {
      if (l > r) return;
      norm(new_pref[l] += val);
      norm(new_pref[r + 1] -= val);
    };
    
    for (int j = 1; j <= n; j++) {
      if (j == b) continue;
      int en_high = j > b ? min(n, j + abs(b - j) - 1) : min(b, j + abs(b - j) - 1);
      int st_high = min(n, j + 1);
      int st_low = j < b ? max(1, j - abs(b - j) + 1) : max(b, j - abs(b - j) + 1);
      int en_low = max(1, j - 1);

      if (st_low < j && en_low < j) update(st_low, en_low, dp[i][j]);
      if (st_high > j && en_high > j) update(st_high, en_high, dp[i][j]);
    }

    dp[i + 1][0] = new_pref[0];
    for (int j = 1; j <= n; j++) {
      norm(dp[i + 1][j] += dp[i + 1][j - 1]);
      norm(dp[i + 1][j] += new_pref[j]);
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == b) continue;
    norm(ans += dp[k][i]);
  }
  
  cout << ans;
  return 0;
}
