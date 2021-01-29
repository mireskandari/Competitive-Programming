#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> c(n), a(n), b(n);
		for (auto &i : c) {
			cin >> i;
			--i;
		}
		for (auto &i : a) {
			cin >> i;
		}
		for (auto &i : b) {
			cin >> i;
		}
		for (int i = 0; i < n; ++i) {
			if (b[i] < a[i]) {
				swap(a[i], b[i]);
			}
		}
		long long ans = LLONG_MIN;
		vector<long long> dp(n);
		dp[1] = c[1] + 2 + b[1] - a[1];
		ans = max(ans, dp[1]);
		//cerr << dp[1] << ' ';
		for (int i = 2; i < n; ++i) {
			dp[i] = max(c[i] + 2 + b[i] - a[i], 1ll * (b[i] != a[i]) * (dp[i - 1] - (b[i] - a[i]) + 2 + c[i]));
			//cerr << dp[i] << ' ';
			ans = max(ans, dp[i]);
		}
		cout << ans << '\n';
	}

}

