#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const volatile auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define SHOW(a) #a << "=" << (a) << ", "

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1010;

int n, m, k;
vector<pair<int, int>> g[N];
pair<int, int> edge[N];
int dist[N][N];
bool mark[N];
pair<int, int> route[N];

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    g[--v].emplace_back(--u, w);
    g[u].emplace_back(v, w);
    edge[i] = {v, u};
  }
  for (int i = 0; i < n; ++i) {
    fill_n(dist[i], N, INF);
    memset(mark, 0, sizeof(mark));
    using Type = pair<int, int>;
    priority_queue<Type, vector<Type>, greater<>> pq;
    pq.emplace(0, i);
    dist[i][i] = 0;
    while (!pq.empty()) {
      auto [_, v] = pq.top();
      pq.pop();
      if (mark[v]) continue;
//      cerr << "v is now: " << SHOW(v) << "\n";
      mark[v] = true;
      for (auto& [u, w] : g[v]) {
        if (!mark[u]) {
          if (dist[i][u] > dist[i][v] + w) {
            dist[i][u] = dist[i][v] + w;
            pq.emplace(dist[i][u], u);
          }
        }
      }
    }
    for (int j = 0; j < n; ++j) {
//      cerr << SHOW(i + 1) << SHOW(j + 1) << SHOW(dist[i][j]) << "\n";
    }
  }
  for (int i = 0; i < k; ++i) {
    int v, u;
    cin >> v >> u;
    route[i] = {--v, --u};
  }
  int ans = INF;
  for (int i = 0; i < m; ++i) {
    auto& [v, u] = edge[i];
    int now = 0;
    for (int j = 0; j < k; ++j) {
      auto& [a, b] = route[j];
      now += min({dist[a][b], dist[a][v] + dist[u][b], dist[a][u] + dist[v][b]});
    }
//    cerr << SHOW(v) << SHOW(u) << SHOW(now) << "\n";
    ans = min(now, ans);
  }
  cout << ans;
  return 0;
}
