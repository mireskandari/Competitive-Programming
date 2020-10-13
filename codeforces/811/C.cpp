#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define err(a...) fprintf(stderr, a)
typedef long long ll;

constexpr int N = 5e3 + 10;

int a[N], dp[N], l[N], r[N], xorr[N];
bool mark[N], exist[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (l[a[i]] == 0) l[a[i]] = i;
  }
  for (int i = n; i > 0; --i) {
    if (r[a[i]] == 0) r[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    memset(mark, false, sizeof(mark));
    xorr[i] = a[i];
    mark[a[i]] = true;
    for (int j = i - 1; j > 0; --j) {
      xorr[j] = xorr[j + 1];
      if (!mark[a[j]]) {
        mark[a[j]] = true;
        xorr[j] ^= a[j];
      }
      //err("xorr[%d][%d] = %d\n", j, i, xorr[j][i]);
    }
    exist[i] = r[a[i]] > i;
    for (int j = i - 1; j > 0; --j) {
      exist[j] = exist[j + 1] || r[a[j]] > i;
    }
    //err("i = %d\n", i);
    dp[i] = dp[i - 1];
    int mn = l[a[i]];
    for (int j = i; j > 0; --j) {
      if (r[a[j]] > i) break;
      mn = min(mn, l[a[j]]);
      if (exist[mn]) break;
      assert(mn > 0);
      if (mn == j) {
        dp[i] = max(dp[i], xorr[mn] + dp[mn - 1]);
      }
    }
  }
  printf("%d", dp[n]);
  return 0;
}
