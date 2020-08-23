#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define eb(a) emplace_back(a)
#define mp(a, b) make_pair(a, b)
typedef long long ll;

int constexpr N = 300, Z = 110;

int n, k;
char s[N];
// position, change count, direction
bool dp[N][N][2], new_dp[N][N][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s >> k;
  n = strlen(s);
  
  dp[Z][0][0] = dp[Z][0][1] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 100; ++j) { // delta from Z
      for (int x = 0; x <= k; ++x) {
        for (int b = 0; b < 2; ++b) {
          int d = b ? -1 : 1;
          
          vector<int> arr{Z + j, Z - j};
          for (auto &p : arr) {
            if (s[i - 1] == 'F') {
              new_dp[p][x][b] = dp[p + d][x][b];
              if (x > 0) {
                new_dp[p][x][b] |= dp[p][x - 1][!b];
              }
              if (x > 1) {
                new_dp[p][x][b] |= new_dp[p][x - 2][b];
              }
            } else {
              new_dp[p][x][b] = dp[p][x][!b];
              if (x > 0) {
                new_dp[p][x][b] |= dp[p + d][x - 1][b];
              }
              if (x > 1) {
                new_dp[p][x][b] |= new_dp[p][x - 2][b];
              }
            }
          }

        }
      }
    }
    memcpy(dp, new_dp, sizeof(dp));
  }

  int best = INT_MIN;
  for (int i = -100; i <= 100; ++i) {
    if (dp[Z + i][k][0] || dp[Z + i][k][1]) {
      best = max(best, abs(i));
    }
  }

  cout << best;
  return 0;
}

