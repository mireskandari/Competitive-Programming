#include <bits/stdc++.h>
using namespace std;

const volatile auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define SHOW(a) #a << "=" << (a) << ", "

void SetMax(int64_t& a, int64_t b) {
	a = max(a, b);
}

constexpr int N = 105;
constexpr int64_t INF = 1e14;

int64_t dp[N][N][N], mx_dp[N][N];
char s[N];
int a[N];

int main() {
	int n;
	cin >> n;
	cin >> (s + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	fill_n(&dp[0][0][0], N * N * N, -INF);
	fill_n(&mx_dp[0][0], N * N, -INF);
	for (int i = 1; i <= n; ++i) {
		dp[i][i][1] = a[1];
		mx_dp[i][i] = a[1];
	}
	auto GetMax = [&](int l, int r) -> int64_t {
		if (r < l) return 0;
		return mx_dp[l][r];
	};
	for (int i = n; i >= 1; --i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = 1; k <= j - i; ++k) {
				SetMax(dp[i][j][1], dp[i + 1][j][k]);
			}
			dp[i][j][1] += a[1];
			for (int k = 2; k <= j - i + 1; ++k) {
				for (int x = i + 1; x <= j; ++x) {
					if (s[x] == s[i]) {
						SetMax(dp[i][j][k], GetMax(i + 1, x - 1) + dp[x][j][k - 1] - a[k - 1] + a[k]);
					}
				}
			}
			for (int k = 1; k <= j - i + 1; ++k) {
				SetMax(mx_dp[i][j], dp[i][j][k]);
			}
		}
	}
	cout << GetMax(1, n);
	return 0;
}
// dp[l][r][k]: ans for [l, r] such that a[l] gets deleted in a sequence of length k
