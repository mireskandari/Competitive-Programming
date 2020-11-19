#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr int MOD = 998244353;

int Power(int a, int b) {
	int res = 1;
	for (; b > 0; b >>= 1, a = 1ll * a * a % MOD) if (b & 1) res = 1ll * res * a % MOD;
	return res;
}

constexpr int N = 2e5 + 10;

int dp[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int sumeven = 0;
	int sumodd = 1;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (i & 1) {
			dp[i] = sumodd;
			sumeven += dp[i]; sumeven %= MOD;
		} else {
			dp[i] = sumeven;
			sumodd += dp[i]; sumodd %= MOD;
		}
	}
	cout << (long long) dp[n] % MOD * Power(Power(2, n), MOD - 2) % MOD;
	return 0;
}

