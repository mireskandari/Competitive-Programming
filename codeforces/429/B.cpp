#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a, b) ({__typeof__(a) _a = (a); __typeof__(b) _b = (b); _a > _b ? _a : _b; })

typedef long long ll;

#define N 1100

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  static ll a[N][N];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%lld", &a[i][j]);
    }
  }
  
  // first motherfucker
  static ll path1[N][N], path3[N][N];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      path1[i][j] = max(path1[i - 1][j], path1[i][j - 1]) + a[i][j];
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 1; --j) {
      path3[i][j] = max(path3[i + 1][j], path3[i][j + 1]) + a[i][j];
    }
  }

  // second motherfucker
  static ll path2[N][N], path4[N][N];
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= m; ++j) {
      path2[i][j] = max(path2[i + 1][j], path2[i][j - 1]) + a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= 1; --j) {
      path4[i][j] = max(path4[i][j + 1], path4[i - 1][j]) + a[i][j];
    }
  }
  
  // 1 4
  // 2 3

  ll best = 0;
  for (int i = 2; i <= n - 1; ++i) {
    for (int j = 2; j <= m - 1; ++j) {
      ll f = path1[i][j - 1] + path2[i + 1][j] + path3[i][j + 1] + path4[i - 1][j];
      ll s = path1[i - 1][j] + path2[i][j - 1] + path3[i + 1][j] + path4[i][j + 1];
      ll rhs = max(f, s);
      best = max(best, rhs);
    }
  }

  printf("%lld", best);
  return 0;
}
