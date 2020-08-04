#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) v.begin(), v.end()
#define X first
#define Y second
#define int ll

using ll = long long; using ld = long double;

template <class T = int> using V = vector<T>;
template <class T = int> using VV = V<V<T>>;
template <class T = int> using PP = pair<T, T>;

int constexpr MOD = 1e9 + 7;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  V<> a(k);
  for (auto &i : a) cin >> i;
  VV<> ncr(2001, V<>(2001));
  ncr[0][0] = 1;
  for (int i = 0; i < 2001; i++) {
    for (int j = 0; j < 2001; j++) {
      if (i + j == 0) continue;
      ncr[i][j] = ((i > 0 && j > 0 ? ncr[i - 1][j - 1] : 0) + (i > 0 ? ncr[i - 1][j] : 0)) % MOD;
    }
  }
  V<> dp(k);
  dp[0] = 1;
  int sum = a[0];
  for (int i = 1; i < k; i++) {
    dp[i] = (dp[i - 1] * ncr[sum + a[i] - 1][a[i] - 1]) % MOD;
    sum += a[i];
  }

  cout << dp[k - 1];
  return 0;
}
