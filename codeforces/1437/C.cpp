#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 1000;

int a[N];
int64 dp[N][N];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		fill_n(&dp[0][0], N * N, 1e12);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < N; ++j) {
				dp[i][j] = abs(a[i] - j) + (i > 0 ? *min_element(dp[i - 1] + i, dp[i - 1] + j) : 0);
			}
		}
		int64 ans = *min_element(dp[n - 1] + 1, dp[n - 1] + N);
		printf("%lld\n", ans);
	}
	return 0;
}
