#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define ERR(a...) fprintf(stderr, a)
using ll = long long;

constexpr int N = 1e6 + 10;

ll a[N];
tuple<ll, ll, ll> dp[2][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  dp[0][0] = dp[1][0] = {0, a[0], a[0]};
  for (int i = 1; i < n; ++i) {
    dp[0][i] = {get<0>(dp[1][i - 1]), a[i], a[i]};
    {
      ll ans, mx, mn; 
      tie(ans, mx, mn) = dp[1][i - 1];
      if (a[i] > mx) {
        ans += a[i] - mx;
        mx = a[i];
      } else if (a[i] < mn) {
        ans += mn - a[i];
        mn = a[i];
      }
      dp[1][i] = {ans, mx, mn};
    }
    {
      ll ans, mx, mn;
      tie(ans, mx, mn) = dp[0][i - 1];
      if (a[i] > mx) {
        ans += a[i] - mx;
        mx = a[i];
      } else if (a[i] < mn) {
        ans += mn - a[i];
        mn = a[i];
      }
      if (ans > get<0>(dp[1][i])) {
        dp[1][i] = {ans, mx, mn};
      }
    }
  }
  printf("%lld", max(get<0>(dp[1][n - 1]), get<0>(dp[0][n - 1])));
  return 0;
}