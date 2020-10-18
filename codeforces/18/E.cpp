#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ERR(a...) fprintf(stderr, a)

bool ChMin(int &a, int b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

constexpr int N = 510;

char a[N][N];
int dp[N][30][30];
pair<int, int> parent[N][30][30];
int cost[30][30];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
  }
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    memset(cost, 0x3f, sizeof(cost));
    for (int f = 0; f < 26; ++f) {
      for (int s = 0; s < 26; ++s) {
        if (f == s) continue;
        cost[f][s] = 0;
        for (int j = 0; j < m; ++j) {
          cost[f][s] += (int) (a[i][j] != (j & 1 ? (char) s + 'a' : (char) f + 'a'));
        }
        if (i == 0) {
          dp[i][f][s] = cost[f][s];
        } else {
          for (int p = 0; p < 26; ++p) {
            for (int k = 0; k < 26; ++k) {
              if (p == f || k == s || p == k) continue;
              if (ChMin(dp[i][f][s], dp[i - 1][p][k] + cost[f][s])) {
                parent[i][f][s] = {p, k};
              }
            }
          }
        }
      }
    }
  }
  int f = -1, s = -1;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (f == -1 || dp[n - 1][f][s] > dp[n - 1][i][j]) {
        f = i, s = j;
      }
    }
  }
  printf("%d\n", dp[n - 1][f][s]);
  static array<char, 2> ans[N];
  for (int i = n - 1; i >= 0; --i) {
    char ff = (char) (f + 'a'), ss = (char) (s + 'a');
    ans[i] = {ff, ss};
    tie(f, s) = parent[i][f][s];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      putchar(ans[i][j & 1]);
    }
    putchar('\n');
  }
  return 0;
}
