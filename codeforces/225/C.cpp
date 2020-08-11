#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) 42
#endif

#define cmp(a, op, b) ({__typeof__(a) _a = a; __typeof__(b) _b = b; _a op _b ? _a : _b; })

typedef long long ll;

#define N 1010

int main() {
  int n, m, x, y;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  static char a[N][N]; // 0
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
  }
  
  // count
  static int cnt[N][2]; // 0
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (a[i][j] == '#') cnt[j][1]++;
      else cnt[j][0]++;
    }
  }

  // prefix
  static int pref[N][2]; // 1
  for (int j = 0; j < m; ++j) {
    for (int x = 0; x < 2; ++x) {
      pref[j + 1][x] = pref[j][x] + cnt[j][x];
    }
  }
  
  // the boss
  static ll dp[N][2]; // 1
  dp[0][0] = 0, dp[0][1] = 0;
  for (int i = 1; i <= m; ++i) {
    dp[i][0] = dp[i][1] = 1e14;

    int start = cmp(i - x, >, 0), end = cmp(i - y, >, 0);
    for (int j = end; j <= start; ++j) {
      if (i - j < x || i - j > y) continue;
      for (int x = 0; x < 2; ++x) {
        int change = pref[i][!x] - pref[j][!x];
        dp[i][x] = cmp(dp[i][x], <, dp[j][!x] + change);
      }
    }
  }

  // done.
  printf("%lld", cmp(dp[m][0], <, dp[m][1]));
  return 0;
}
