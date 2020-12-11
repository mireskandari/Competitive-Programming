#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> dp(n, vector<int>(m));
		vector<string> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		long long ans = 0;
		for (int i = 0; i < m; ++i) {
			if (a[0][i] != '*') {
				continue;
			}
			dp[0][i] = 1;
			ans += dp[0][i];
		}
		for (int i = 1; i < n; ++i) {
			int last = a[i][0] == '*' ? 0 : -1;
			dp[i][0] = a[i][0] == '*';
			ans += dp[i][0];
			for (int j = 1; j < m; ++j) {
				if (a[i][j] != '*') {
					last = -1;
					continue;
				}
				if (last == -1) {
					last = j;
				}
				dp[i][j] = min(dp[i - 1][j - 1] + 1, (j - last + 2) / 2);
				ans += dp[i][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

