#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define err(a...) fprintf(stderr, a)
typedef long long ll;

constexpr int N = 1e5 + 10;

vector<int> g[N];
int dist_a[N], dist_all[N];

void Dfs(int v, int p, int *dist) {
  for (auto &u : g[v]) {
    if (u == p) continue;
    dist[u] = dist[v] + 1;
    Dfs(u, v, dist);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, a, b, da, db;
    fill_n(g, n + 1, vector<int>());
    memset(dist_a, 0, sizeof(int) * (n + 1));
    memset(dist_all, 0, sizeof(int) * (n + 1));
    scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
    for (int i = 0; i < n - 1; ++i) {
      int v, u;
      scanf("%d %d", &v, &u);
      g[v].push_back(u);
      g[u].push_back(v);
    }
    Dfs(a, -1, dist_a);
    Dfs(max_element(dist_a + 1, dist_a + n + 1) - dist_a, -1, dist_all);
    auto Bye = [](bool alice) {
      puts(alice ? "Alice" : "Bob");
    };
    int diam = *max_element(dist_all + 1, dist_all + n + 1);
    if (dist_a[b] <= da) {
      Bye(true);
    } else if (diam <= 2 * da) {
      Bye(true);
    } else if (db > 2 * da) {
      Bye(false);
    } else if (db <= 2 * da) {
      Bye(true);
    } else {
      assert(false);
    }
  }
  return 0;
}
