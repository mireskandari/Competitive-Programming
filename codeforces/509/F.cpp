#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

int n, a[512], dp[512][512];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = n - 1; i >= 0; --i) {
		dp[i][i] = 1;
		for (int j = i + 1; j < n; ++j) {
			dp[i][j] = dp[i + 1][j];
			for (int x = i + 1; x < j; ++x) {
				if (a[i + 1] < a[x + 1]) {
					dp[i][j] += 1ll * dp[i + 1][x] * dp[x][j] % MOD;
					if (dp[i][j] >= MOD) {
						dp[i][j] -= MOD;
					}
				}
			}
		}
	}

	cout << dp[0][n - 1];
}