#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 998244353;

void ok(int &a) {
	if (a >= MOD) {
		a -= MOD;
	}
	if (a < 0) {
		a += MOD;
	}
}

int mult(int a, int b) {
	return 1ll * a * b % MOD;
}

int power(int n, int k) {
	int res = 1;
	for (; k; k >>= 1, n = mult(n, n)) {
		if (k & 1) {
			res = mult(res, n);
		}
	}
	return res;
}

int inv[5010];

int ncr(int n, int k) {
	if (n < 0 || k < 0 || n < k) {
		return 0;
	}
	int ret = 1;
	for (int i = n - k + 1; i <= n; ++i) {
		ret = mult(ret, i);
	}
	for (int i = 1; i <= k; ++i) {
		ret = mult(ret, inv[i]);
	}
	return ret;
}

int dp[5010][5010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 1; i <= 5000; ++i) {
		inv[i] = power(i, MOD - 2);
	}


	int n, m, k;
	cin >> n >> m >> k;
	
	dp[0][0] = 1;
	for (int i = 0; i <= 5000; ++i) {
		for (int j = 0; j <= 5000; ++j) {
			if (i + j) {
				dp[i][j] = (i && j ? dp[i - 1][j - 1] : 0);
				ok(dp[i][j] += (i ? dp[i - 1][j] : 0));
				dp[i][j] = mult(dp[i][j], j);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= k; ++i) {
		int coeff = power(power(m, i), MOD - 2);
		ok(ans += mult(ncr(n, i), mult(dp[k][i], coeff)));
	}

	cout << ans;
}