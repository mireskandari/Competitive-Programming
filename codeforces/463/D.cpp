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
  int n, k; cin >> n >> k;
  vc<vc<int>> a(k, vc<int>(n));
  for (auto &v : a) for (auto &i : v) cin >> i;
  vc<vc<int>> pos(k, vc<int>(n + 1));
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j <= n; ++j) {
      pos[i][a[i][j - 1]] = j;
    }
  }
  vc<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    for (int j = 1; j < i; ++j) {
      bool correct = true;
      for (int x = 0; x < k; ++x) {
        correct &= pos[x][a[0][j - 1]] < pos[x][a[0][i - 1]];
      }
      if (!correct) continue;
      dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  cout << *max_element(all(dp));
  return 0;
}
