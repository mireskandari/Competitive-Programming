#include <bits/stdc++.h>
using namespace std;
#define err(a...) fprintf(stderr, a)

bool chmax(int &a, int b) {
  if (a >= b) {
    return false;
  } else {
    a = b;
    return true;
  }
}

constexpr int N = 510;
constexpr int PICK = 1, NPICK = 0;

int a[N], b[N];
int dp[N][N];
array<int, 3> parent[N][N];

int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        dp[i][j] = 1;
        parent[i][j] = {PICK, 0, 0};
        for (int k = 1; k < j; ++k) {
          if (b[k] < b[j]) {
            if (chmax(dp[i][j], dp[i - 1][k] + 1))
              parent[i][j] = {PICK, i - 1, k};
          }
        }
      }
      if (chmax(dp[i][j], dp[i - 1][j])) {
        parent[i][j] = {NPICK, i - 1, j};
      }
    }
  }
  
  int mxi = -1;
  for (int i = 1; i <= m; ++i)
    if (mxi == -1 || dp[n][i] > dp[n][mxi])
      mxi = i;

  printf("%d\n", dp[n][mxi]);

  int i = n, j = mxi;
  vector<int> ans;
  while (i > 0 && j > 0) {
    if (parent[i][j][0] == PICK) {
      ans.push_back(a[i]);
    }
    auto p = parent[i][j];
    i = p[1], j = p[2];
  }
  reverse(begin(ans), end(ans));

  for (auto &i : ans)
    printf("%d ", i);
  return 0;
}
