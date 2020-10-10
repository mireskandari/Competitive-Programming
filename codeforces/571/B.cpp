#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define long long long
#define err(a...) fprintf(stderr, a)

constexpr int N = 3e5 + 10;
constexpr int K = 5010;
constexpr int INF = 2e9;

int a[N], dp[K][K];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  fill(&dp[0][0], &dp[K - 1][K - 1] + 1, INF);
  dp[0][0] = 0;
  int each = n / k, big = n % k;
  for (int large = 0; large <= big; ++large) {
    for (int small = 0; small <= k - big; ++small) {
      int nx = large * (each + 1) + small * each;
      if (large < big) {
        int added = a[nx + each] - a[nx];
        dp[large + 1][small] = min(dp[large + 1][small], dp[large][small] + added);
      }
      if (small < k - big) {
        int added = a[nx + each - 1] - a[nx];
        dp[large][small + 1] = min(dp[large][small + 1], dp[large][small] + added);
      }
    }
  }
  printf("%d", dp[big][k - big]);
  return 0;
}
