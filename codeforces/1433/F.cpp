#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

volatile auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define ERR(a...) fprintf(stderr, a)

void SetMax(int &a, int b) {
  a = max(a, b);
}

constexpr int N = 80;

int n, m, k;
int a[N][N], dp1[N][N][N], dp2[N][N], best[N];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  fill(&dp2[0][0], &dp2[N - 1][N - 1] + 1, (int)-1e8);
  dp2[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    fill(&dp1[0][0][0], &dp1[N - 1][N - 1][N - 1] + 1, (int)-1e8);
    dp1[0][0][0] = 0;
    for (int j = 0; j < m; ++j) {
      dp1[j + 1][0][0] = 0;
      for (int mod = 0; mod < k; ++mod) {
        for (int many = 0; many <= m / 2; ++many) {
          SetMax(dp1[j + 1][mod][many], dp1[j][mod][many]);
          if (many + 1 <= m / 2) {
            SetMax(dp1[j + 1][(mod + a[i][j + 1]) % k][many + 1], dp1[j][mod][many] + a[i][j + 1]);
          }
        }
      }
    }
    fill(best, best + N, (int)-1e8);
    for (int j = 0; j <= m / 2; ++j) {
      for (int mod = 0; mod < k; ++mod) {
        SetMax(best[mod], dp1[m][mod][j]);
      }
    }
    for (int mod1 = 0; mod1 < k; ++mod1) {
      for (int mod2 = 0; mod2 < k; ++mod2) {
        SetMax(dp2[i][(mod1 + mod2) % k], dp2[i - 1][mod1] + best[mod2]);
      }
    }
  }
  cout << dp2[n][0];
  return 0;
}
