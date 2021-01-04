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
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		vector<long long> dp(n);
		dp[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			dp[i] = 1ll * a[i] + (i + a[i] < n ? dp[i + a[i]] : 0);
		}
		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}
	return 0;
}

