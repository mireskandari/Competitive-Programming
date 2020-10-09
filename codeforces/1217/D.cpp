#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int N = 5010;

struct edge_t {
  int v, u;
} edge[N];

vector<int> g[N];
int mark[N], color[N];

void dfs(int v) {
  mark[v] = 1;
  for (auto idx : g[v]) {
    if (edge[idx].u == v) swap(edge[idx].u, edge[idx].v);
    if (mark[edge[idx].u] == 1) {
      color[idx] = 2;
    } else if (mark[edge[idx].u] == 0) {
      dfs(edge[idx].u);
    }
  }
  mark[v] = 2;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d %d", &v, &u);
    edge[i] = (edge_t) {v, u};
    g[v].push_back(i);
  }
  fill_n(color, m, 1);
  for (int i = 0; i < n; ++i) {
    if (mark[i] == 0) dfs(i);
  }
  if (count(color, color + m, 2) == 0) {
    puts("1");
    for (int i = 0; i < m; ++i) {
      putchar('1'); putchar(' ');
    }
  } else {
    puts("2");
    for (int i = 0; i < m; ++i) {
      printf("%d ", color[i]);
    }
  }
  return 0;
}
