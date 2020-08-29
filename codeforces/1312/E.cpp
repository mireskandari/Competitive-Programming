#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define vc vector

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vc<int> a(n); for (auto &i : a) cin >> i;
  vc<vc<int>> shrink(n + 1, vc<int>(n + 1, -1));
  for (int i = 0; i < n; ++i) shrink[i][i] = a[i];
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      for (int x = i; x <= j; ++x) {
        if (shrink[i][x] != -1 && shrink[i][x] == shrink[x + 1][j]) {
          shrink[i][j] = shrink[i][x] + 1;
          break;
        }
      }
    }
  }
  vc<vc<int64_t>> dp(n + 1, vc<int64_t>(n + 1, 1e14));
  for (int i = 0; i < n; ++i) dp[i][i] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      for (int x = i; x <= j; ++x) {
        int64_t temp = dp[i][x] + dp[x + 1][j];
        if (shrink[i][x] != -1 && shrink[i][x] == shrink[x + 1][j]) --temp;
        dp[i][j] = min(dp[i][j], temp);
      }
    }
  }
  cout << dp[0][n - 1];
  return 0;
}
