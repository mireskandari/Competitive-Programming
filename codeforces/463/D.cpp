#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ERR(a...) fprintf(stderr, a)

constexpr int N = 1010;

vector<int> g[N];
int a[N][10], dp[N], pos[N][50];

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
    for (int j = i + 1; j <= n; ++j) {
      if (i == j) continue;
      bool ok = true;
      for (int x = 1; x <= k; ++x) {
        if (pos[a[i][1]][x] > pos[a[j][1]][x]) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      g[i].push_back(j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto& u : g[i]) {
      dp[u] = max(dp[u], dp[i] + 1);
    }
  }
  printf("%d", *max_element(dp, dp + N) + 1);
  return 0;
}
