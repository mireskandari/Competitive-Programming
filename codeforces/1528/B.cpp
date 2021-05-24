#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int MD = 998244353;

constexpr int N = 3e6 + 10;

int dp[N], dv[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	dp[0] = dp[1] = 1;
	int sum = 2;
	for (int i = 2; i <= 2 * n; i += 2) {
		for (int j = i * 2; j <= 2 * n; j += i) {
			dv[j]++;
		}
	}

	for (int i = 2; i <= n; ++i) {
		dp[i] = sum + dv[2 * i];
		dp[i] %= MD;
		sum += dp[i];
		sum %= MD;
	}

	cout << dp[n];
}