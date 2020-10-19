#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ERR(a...) fprintf(stderr, a)

constexpr int MOD = 1000000007;

inline void Add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

// Based on Lindström–Gessel–Viennot lemma :/

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> a(n + 1);
  a[0] = string(m + 1, '#');
  for (int i = 1; i <= n; ++i) {
    static char s[3010];
    s[0] = '#';
    scanf("%s", s + 1);
    a[i] = s;
  }
  vector<vector<int>> dp_a(n + 1, vector<int>(m + 1)), dp_b(n + 1, vector<int>(m + 1));
  auto Ok = [&](int i, int j) {
    return a[i][j] != '#';
  };
  dp_a[1][2] = 1;
  dp_b[2][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!Ok(i, j)) continue;
      if (i > 1 || j >= 2) {
        if (Ok(i - 1, j)) Add(dp_a[i][j], dp_a[i - 1][j]);
        if (Ok(i, j - 1)) Add(dp_a[i][j], dp_a[i][j - 1]);
      }
      if (j > 1 || i >= 2) {
        if (Ok(i - 1, j)) Add(dp_b[i][j], dp_b[i - 1][j]);
        if (Ok(i, j - 1)) Add(dp_b[i][j], dp_b[i][j - 1]);
      }
    }
  }
  int ans = 1ll * dp_a[n - 1][m] * dp_b[n][m - 1] % MOD;
  Add(ans, (-1ll * dp_a[n][m - 1] * dp_b[n - 1][m] % MOD + MOD) % MOD);
  printf("%d", ans);
  return 0;
}
