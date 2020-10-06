#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int N = 5010;

char s[N]; 
bool dp[N][N];
int pref[N][N], ans[N][N];

int main() {
  scanf("%s", s);
  int n = (int) strlen(s);
  for (int i = n - 1; i >= 0; --i) {
    dp[i][i] = true; 
    if (i < n - 1) dp[i][i + 1] = s[i] == s[i + 1];
    for (int j = i + 2; j < n; ++j) dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
  }
  for (int i = 0; i < n; ++i) 
    for (int j = i; j < n; ++j) { pref[i][j] = (j != i ? pref[i][j - 1] : 0) + dp[i][j]; }
  for (int i = n - 1; i >= 0; --i) 
    for (int j = i; j < n; ++j) { ans[i][j] += pref[i][j] + (i < n - 1 ? ans[i + 1][j] : 0); }
  int q;
  scanf("%d", &q);
  while (q--) { int l, r; scanf("%d %d", &l, &r); printf("%d\n", ans[l - 1][r - 1]); }
  return 0;
}
