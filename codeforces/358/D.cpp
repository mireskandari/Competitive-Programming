#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  for (auto &i : c) cin >> i;
  
  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  dp[1][0] = a[0], dp[1][1] = b[0];
  for (int i = 2; i <= n; i++) {
    dp[i][0] = max<ll>(dp[i - 1][0] + b[i - 1], dp[i - 1][1] + a[i - 1]);
    dp[i][1] = max<ll>(dp[i - 1][0] + c[i - 1], dp[i - 1][1] + b[i - 1]);
    cerr << dp[i][0] << ' ' << dp[i][1] << '\n';
  }

  cout << dp[n][0];
  return 0;
}
