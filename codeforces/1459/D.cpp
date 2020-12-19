#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

constexpr int mxn = 1e2 + 10, mxw = mxn * mxn, inf = 0x3f3f3f3f;

int n, a[mxn], b[mxn], dp[mxn][mxw], new_dp[mxn][mxw];
double ans[mxn];

int main() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		sum += b[i];
	}
	fill_n(&dp[0][0], mxn * mxw, -inf);
	fill_n(&new_dp[0][0], mxn * mxw, -inf);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k < mxw; ++k) {
				new_dp[j][k] = dp[j][k];
				if (j > 0 && k >= a[i]) {
					new_dp[j][k] = max(dp[j - 1][k - a[i]] + b[i], new_dp[j][k]);
				}
				if (new_dp[j][k] >= 0) {
					ans[j] = max(ans[j], 1.0 * new_dp[j][k] + min(1.0 * (sum - new_dp[j][k]) / 2.0, 1.0 * k - 1.0 * new_dp[j][k]));
				}
			}
		}
		swap(dp, new_dp);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%.15lf ", ans[i]);
	}
	return 0;
}

