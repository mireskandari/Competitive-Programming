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
		vector<long long> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		vector<long long> tm(n);
		for (int i = 0; i < n; ++i) {
			cin >> tm[i];
		}
		vector<long long> dp(n);
		dp[0] = a[0] + tm[0];
		for (int i = 1; i < n; ++i) {
			dp[i] = max(dp[i - 1] + (b[i - 1] - a[i - 1] + 1) / 2, b[i - 1]) + (a[i] - b[i - 1] + tm[i]);
		}
		cout << dp[n - 1] << '\n';
	}
}