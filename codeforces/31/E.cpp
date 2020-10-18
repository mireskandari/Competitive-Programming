#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ERR(a...) fprintf(stderr, a)

int main() {
  int n;
  scanf("%d", &n);
  static char s[100];
  scanf("%s", s + 1);
  vector<vector<pair<ll, int>>> dp(n + 1, vector<pair<ll, int>>(n + 1, {-1, 0}));
  vector<ll> pw10(20);
  pw10[0] = 1;
  for (int i = 1; i < 19; ++i) {
    pw10[i] = pw10[i - 1] * 10;
  }
  dp[0][0] = {0, 0};
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i + j == 0) continue;
      if (i > 0 && dp[i - 1][j].first >= 0) {
        auto [val, parent] = dp[i - 1][j];
        val += pw10[n - i] * (ll) (s[i + j] - '0');
        dp[i][j] = {val, 0};
      }
      if (j > 0 && dp[i][j - 1].first >= 0) {
        auto [val, parent] = dp[i][j - 1];
        val += pw10[n - j] * (ll) (s[i + j] - '0');
        if (dp[i][j].first == -1 || dp[i][j].first < val) {
          dp[i][j] = {val, 1};
        }
      }
    }
  }
  int i = n, j = n;
  string ans;
  while (i + j > 0) {
    auto [_, who] = dp[i][j];
    if (who == 0) {
      ans += "H";
      --i;
    } else {
      ans += "M";
      --j;
    }
  }
  reverse(ans.begin(), ans.end());
  printf("%s", ans.c_str());
  return 0;
}