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
  vc<pair<int, int>> e(m);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[--v].emplace_back(i);
    g[--u].emplace_back(i);
    e[i] = make_pair(u, v);
  }
  // dp[v] : edges passing by the edge {v, P(v)}
  vc<int> dp(n), depth(n);
  vc<bool> mark(n);
  function<void(int)> dfs = [&](int v) {
    mark[v] = true;
    for (auto &edge : g[v]) {
      int u = e[edge].first + e[edge].second - v;
      if (mark[u] && depth[u] < depth[v] - 1) {
        cerr << v << ' ' << u << '\n';
        --dp[u]; ++dp[v];
        if (e[edge].first != v) swap(e[edge].first, e[edge].second);
      }
    }
    for (auto &edge : g[v]) {
      int u = e[edge].first + e[edge].second - v;
      if (!mark[u]) {
        depth[u] = depth[v] + 1;
        dfs(u);
        dp[v] += dp[u];
        if (e[edge].first != v) swap(e[edge].first, e[edge].second);
      }
    }
  };
  dfs(0);
  for (int i = 1; i < n; ++i) {
    if (!dp[i]) {
      cout << 0;
      exit(0);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << e[i].first + 1 << ' ' << e[i].second + 1 << '\n';
  }
  return 0;
}
