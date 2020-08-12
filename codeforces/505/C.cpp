#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;

int constexpr N = 30010;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, d;
  cin >> n >> d;
  static int a[N];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  static int has[N];
  for (int i = 0; i < n; ++i) {
    has[a[i]]++;
  }
  
  static int dp[N][800];
  memset(dp, -1, sizeof(dp));

  // was hard to fuck with when iterative
  function<int(int, int)> solve = [&](int i, int j) {
    int delta = j - d + 380;
    if (i >= N) return 0;
    if (dp[i][delta] != -1) return dp[i][delta];

    if (j != 1) {
      dp[i][delta] = max({solve(i + j + 1, j + 1), solve(i + j, j), solve(i + j - 1, j - 1)}) + has[i];
    } else {
      dp[i][delta] = max(solve(i + j + 1, j + 1), solve(i + j, j)) + has[i];
    }
    return dp[i][delta];
  };
  
  cout << solve(d, d);
  return 0;
}
