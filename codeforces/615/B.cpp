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
  vc<vc<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int v, u; cin >> v >> u;
    g[--u].emplace_back(--v);
    g[v].emplace_back(u);
  }
  vc<pair<int, int>> dp(n, make_pair(0, -1));
  for (int i = 0; i < n; ++i) {
    for (auto &u : g[i]) {
      if (u > i) continue;
      if (dp[i].first < dp[u].first + 1) {
        dp[i].first = dp[u].first + 1;
        dp[i].second = u;
      }
    }
  }
  int64_t mx = -1;
  for (int i = 0; i < n; ++i) {
    mx = max(mx, (int64_t) g[i].size() * (dp[i].first + 1));
  }
  cout << mx;
  return 0;
}
