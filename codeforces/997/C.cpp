#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 998244353;

int mult(int x, int y) {
	return 1ll * x * y % MOD;
}

void ok(int &a) {
	if (a >= MOD) {
		a -= MOD;
	}
	if (a < 0) {
		a += MOD;
	}
}

int power(int a, int k) {
	int res = 1;
	for (; k; k >>= 1, a = mult(a, a)) {
		if (k & 1) {
			res = mult(res, a);
		}
	}
	return res;
}

constexpr int N = 1e6 + 10;

int fact[N], inv[N], pw[N];

int ncr(int n, int k) {
	if (k < 0 || n < 0 || n < k) {
		return 0;
	}
	return mult(fact[n], mult(inv[n - k], inv[k]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = mult(fact[i - 1], i);
	}
	inv[N - 1] = power(fact[N - 1], MOD - 2);
	for (int i = N - 1; i > 0; --i) {
		inv[i - 1] = mult(inv[i], i);
	}
	pw[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw[i] = mult(pw[i - 1], 3);
	}
	
	int n;
	cin >> n;
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		int tmp = pw[n - i];
		ok(tmp -= 1);
		tmp = power(tmp, n);
		int tmp2 = power(pw[n - i], n);
		ok(tmp -= tmp2);
		ok(ans += (i & 1 ? +1 : -1) * mult(ncr(n, i), tmp));
	}
	
	ans = mult(ans, 3);

	for (int i = n, tmp = 1; i >= 1; --i) {
		ok(ans += (i & 1 ? +2 : -2) * mult(ncr(n, i), mult(pw[i], tmp)) % MOD);
		tmp = mult(tmp, pw[n]);
	}

	cout << ans;
}