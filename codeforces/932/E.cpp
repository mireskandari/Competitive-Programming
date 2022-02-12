#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

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

int power(int x, int k) {
	int res = 1;
	for (; k; k >>= 1, x = mult(x, x)) {
		if (k & 1) {
			res = mult(res, x);
		}
	}
	return res;
}

int inv[5010], dp[5010], nc[5010][5010];

int ncr(int n, int k) {
	if (k < 0 || n < 0 || n < k) {
		return 0;
	}
	int ans = 1;
	for (int i = n - k + 1; i <= n; ++i) {
		ans = mult(ans, i);
	}
	for (int i = 1; i <= k; ++i) {
		ans = mult(ans, inv[i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	nc[0][0] = 1;
	for (int i = 0; i <= 5000; ++i) {
		for (int j = 0; j <= 5000; ++j) {
			if (!i && !j) {
				continue;
			}
			nc[i][j] = (i ? nc[i - 1][j] : 0);
			ok(nc[i][j] += (i && j ? nc[i - 1][j - 1] : 0));
		}
	}

	inv[0] = 1;
	for (int i = 1; i <= 5000; ++i) {
		inv[i] = power(i, MOD - 2);
	}

	int ans = 0;
	
	for (int i = 1; i <= min(n, k); ++i) {
		dp[i] = power(i, k);
		for (int j = 0; j < i; ++j) {
			ok(dp[i] -= mult(nc[i][j], dp[j]));
		}
		ok(ans += mult(power(2, n - i), mult(dp[i], ncr(n, i))));
	}

	cout << ans;
		
}