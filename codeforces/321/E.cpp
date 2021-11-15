#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 4e3 + 10, K = 8e2 + 10;

int n, k, pref[N][N];
pair<int, int> dp[K][N];

int get_sum(int i, int j) {
	return pref[j][j] - pref[j][i - 1] - pref[i - 1][j] + pref[i - 1][i - 1];
}

void solve(int j, int b, int e, int u, int v) {
	if (e - b == 1) {
		for (int i = u; i <= v; ++i) {
			if (i < b) {
				dp[j][b] = min(dp[j][b], make_pair(dp[j - 1][i].first + get_sum(i + 1, b), i));
			}
		}
		return;
	}
	int m = (b + e) >> 1;
	for (int i = u; i <= v; ++i) {
		if (i < m) {
			dp[j][m] = min(dp[j][m], make_pair(dp[j - 1][i].first + get_sum(i + 1, m), i));
		}
	}
	solve(j, b, m, u, dp[j][m].second);
	solve(j, m, e, dp[j][m].second, v);
}

int main() {	
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j].first = dp[i][j].second = 1e9;
		}
	}
	
	scanf("%d%d ", &n, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			pref[i][j] = getchar() - '0';
			getchar();
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}

	for (int i = 0; i <= n; ++i) {
		dp[1][i] = make_pair(pref[i][i], 0);
	}
	for (int i = 1; i <= k; ++i) {
		solve(i, 1, n + 1, 0, n);
	}

	printf("%d", dp[k][n].first / 2);
}
