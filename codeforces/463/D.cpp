#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ERR(a...) fprintf(stderr, a)

constexpr int N = 1010;

vector<int> g[N];
int a[N][10], dp[N], pos[N][50];
char mark[N];

void Go(int v) {
  mark[v] = 1;
  for (auto &u : g[v]) {
    if (mark[u] == 0) {
      Go(u);
    }
    dp[v] = max(dp[v], dp[u] + 1);
  }
  mark[v] = 2;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int j = 1; j <= k; ++j) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int j = 1; j <= k; ++j) {
    for (int i = 1; i <= n; ++i) {
      pos[a[i][j]][j] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      bool ok = true;
      for (int x = 1; x <= k; ++x) {
        if (pos[i][x] > pos[j][x]) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      g[j].push_back(i);
    }
  }
  fill_n(dp, N, 1);
  for (int i = 1; i <= n; ++i) {
    if (mark[i] == 0) Go(i);
  }
  printf("%d", *max_element(dp, dp + N));
  return 0;
}