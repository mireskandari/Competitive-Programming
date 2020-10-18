#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ERR(a...) fprintf(stderr, a)

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    static char s[100];
    scanf("%s", s);
    a[i] = string(s);
  }
  vector<vector<vector<vector<bool>>>> dp(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(m + 1, vector<bool>(n + 1, false))));
  int mx = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      for (int w = 1; w + j <= m; ++w) {
        for (int h = 1; h + i <= n; ++h) {
          if (w == 1 || h == 1) {
            bool ok = true;
            for (int k = 0; k < w; ++k) {
              for (int p = 0; p < h; ++p) {
                ok &= a[i + p][k + j] == '0';
              }
            }
            dp[i][j][w][h] = ok;
          } else {
            dp[i][j][w][h] = dp[i][j][w][1] && dp[i + 1][j][w][h - 1];
          }
          if (dp[i][j][w][h]) {
            mx = max(mx, 2 * w + 2 * h);
          }
        }
      }
    }
  }
  printf("%d", mx);
  return 0;
}