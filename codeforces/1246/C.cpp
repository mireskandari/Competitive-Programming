#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mod = 1000 * 1000 * 1000 + 7;

int add(int a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
	if (a < 0) {
		a += mod;
	}
	return a;
}

constexpr int maxn = 2e3 + 10;

char a[maxn][maxn];
int dp1[maxn][maxn], dp2[maxn][maxn];
int dp1_sum[maxn][maxn], dp2_sum[maxn][maxn];
int col_stone[maxn][maxn], row_stone[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> (a[i] + 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j > 0; --j) {
			row_stone[i][j] = (j < m ? row_stone[i][j + 1] : 0) + (a[i][j] == 'R');
		}
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = n; i > 0; --i) {
			col_stone[j][i] = (i < n ? col_stone[j][i + 1] : 0) + (a[i][j] == 'R');
		}
	}
	dp1[1][1] = 1;
	dp2[1][1] = 1;
	dp1_sum[1][1] = 1;
	dp2_sum[1][1] = 1;
#ifdef LOCAL
	vector<vector<int>> dp1_low(n + 1, vector<int>(m + 1));
	vector<vector<int>> dp2_low(n + 1, vector<int>(m + 1));
#endif
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 1 && j == 1) {
				continue;
			}
			{
				auto check = [&](int mid) {
					return row_stone[i][mid + 1] <= m - j;
				};
				int low = 1, high = j - 1;
				while (high - low > 0) {
					int mid = (low + high) / 2;
					if (!check(mid)) {
						low = mid + 1;
					} else {
						high = mid;
					}
				}
				if (j == 1 || !check(low)) {
					dp2[i][j] = 0;
				} else {
					dp2[i][j] = add(dp1_sum[i][j - 1], -dp1_sum[i][low - 1]);
				}
#ifdef LOCAL
				dp2_low[i][j] = low;
#endif
				dp2_sum[i][j] = add(dp2_sum[i - 1][j], dp2[i][j]);
			}
			{
				auto check = [&](int mid) {
					return col_stone[j][mid + 1] <= n - i;
				};
				int low = 1, high = i - 1;
				while (high - low > 0) {
					int mid = (low + high) / 2;
					if (!check(mid)) {
						low = mid + 1;
					} else {
						high = mid;
					}
				}
				if (i == 1 || !check(low)) {
					dp1[i][j] = 0;
				} else {
					dp1[i][j] = add(dp2_sum[i - 1][j], -dp2_sum[low - 1][j]);
				}
#ifdef LOCAL
				dp1_low[i][j] = low;
#endif
				dp1_sum[i][j] = add(dp1_sum[i][j - 1], dp1[i][j]);
			}
		}
	}
#ifdef LOCAL
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cerr << dp1[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cerr << dp2[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cerr << dp1_low[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cerr << dp2_low[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cerr << dp1_sum[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cerr << dp2_sum[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
#endif
	if (n == 1 && m == 1) {
		cout << 1;
	} else {
		cout << add(dp1[n][m], dp2[n][m]);
	}
	return 0;
}

