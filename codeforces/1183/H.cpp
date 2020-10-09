#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr long INF = 1e12;

void norm(long &a) {
  if (a > INF) a = INF;
}

constexpr int N = 110;

char s[N];
long dp[N][N]; // pref, length
int last[N][30];

int main() {
  int n;
  long k;
  scanf("%d %lld %s", &n, &k, s);
  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; ++i) {
    if (i != 0) memcpy(last[i], last[i - 1], sizeof(last[i]));
    last[i][s[i] - 'a'] = i;
    dp[i][1] = 1;
    /*for (int j = 0; j < 26; ++j) {
      err("last[%d][%d] = %d\n", i, j, last[i][j]);
    }*/
  }
  //err("reached here idiot\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 2; j <= i + 1; ++j) {
      for (int k = 0; k < 26; ++k) {
        if (last[i - 1][k] != -1) norm(dp[i][j] += dp[last[i - 1][k]][j - 1]);
      }
      //err("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
    }
  }
  long have = 0, cost = 0;
  for (int j = n; j > 0; --j) {
    for (int i = 0; i < 26; ++i) {
      if (last[n - 1][i] == -1) continue;
      if (dp[last[n - 1][i]][j] > k - have) {
        cost += (k - have) * (n - j);
        have = k;
      } else {
        cost += dp[last[n - 1][i]][j] * (n - j);
        have += dp[last[n - 1][i]][j];
      }
      if (have >= k) {
        printf("%lld", cost);
        exit(0);
      }
    }
  }
  cost += n;
  have += 1;
  if (have < k) {
    puts("-1");
  } else {
    printf("%lld", cost);
  }
  return 0;
}
