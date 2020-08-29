#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define vc vector

int constexpr LOG = (int) log2(LONG_LONG_MAX);

auto get_bit = [](auto a, int i) { return (a >> i) & 1; };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vc<int64_t> a(n); for (auto &i : a) cin >> i;
  set<pair<int, int>> e;
  vc<set<int>> g(n);
  for (int i = 0; i < LOG; ++i) {
    int cnt = 0;
    vc<int> now;
    for (int j = 0; j < n; ++j) {
      if (get_bit(a[j], i)) {
        now.emplace_back(j);
        cnt++;
      }
    }
    if (cnt >= 3) {
      cout << 3;
      exit(0);
    }
    for (auto &x : now) {
      for (auto &y : now) {
        if (x != y) {
          g[x].emplace(y);
          e.emplace(min(x, y), max(x, y));
        }
      }
    }
  }
  int64_t mn = 1e14;
  // fuck the tests
  for (auto &edge : e) {
    auto rm = edge;
    vc<int64_t> dist(n, 1e14);
    vc<bool> mark(n);
    queue<int> q;
    q.emplace(edge.first);
    dist[edge.first] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto &u : g[v]) {
        if (!mark[u] && make_pair(min(v, u), max(v, u)) != rm) {
          dist[u] = min(dist[u], dist[v] + 1);
          mark[u] = true;
          q.emplace(u);
        }
      }
    }
    mn = min(mn, dist[edge.second] + 1);
  }
      
  cout << (mn >= (int64_t) (1e14) ? -1 : mn);
  return 0;
}
