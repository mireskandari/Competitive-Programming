#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define vc vector

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vc<vc<int>> a(n);
  for (auto &v : a) {
    int sz; cin >> sz;
    v.resize(sz);
    for (auto &i : v) cin >> i;
  }
  vc<vc<int>> max_sum(n);
  for (int i = 0; i < n; ++i) {
    int sz = (int) a[i].size();
    vc<int> pref(sz + 1), suff(sz + 2);
    partial_sum(all(a[i]), pref.begin() + 1);
    partial_sum(a[i].rbegin(), a[i].rend(), suff.rbegin() + 1);
    auto &sum = max_sum[i];
    sum.resize(sz + 1);
    for (int j = 1; j <= sz; ++j) {
      for (int f = 0; f <= j; ++f) {
        int rm = j - f;
        sum[j] = max(sum[j], pref[f] + suff[sz + 1 - rm]);
      }
      cerr << i << ' ' << j << ' ' << sum[j] << '\n';
    }
  }
  vc<vc<int>> dp(n + 1, vc<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int sz = min((int) a[i - 1].size(), j);
      for (int x = 0; x <= sz; ++x) {
        dp[i][j] = max(dp[i][j], max_sum[i - 1][x] + dp[i - 1][j - x]);
      }
    }
  }
  cout << dp[n][m];
  return 0;
}
