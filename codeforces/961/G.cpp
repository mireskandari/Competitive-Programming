#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

int mult(int a, int b) {
	return 1ll * a * b % MOD;
}

void ok(int &a) {
	if (a >= MOD) {
		a -= MOD;
	}
	if (a < 0) {
		a += MOD;
	}
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

constexpr int N = 2e5 + 10;

int f[N], inv[N];

int ncr(int n, int k) {
	if (k < 0 || n < 0 || n < k) {
		return 0;
	}
	return mult(f[n], mult(inv[n - k], inv[k]));
}

int stirling(int n, int k) {
	if (n < k || k < 0 || n < 0) {
		return 0;
	}
	int ret = 0;
	for (int i = 0; i <= k; ++i) {
		ok(ret += ((i + k) & 1 ? -1 : +1) * mult(ncr(k, i), power(i, n)));
	}
	ret = mult(ret, inv[k]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	f[0] = inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = mult(f[i - 1], i);
		inv[i] = power(f[i], MOD - 2);
	}

	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int w;
		cin >> w;
		ok(sum += w);
	}
	
	int coeff = stirling(n, k) + mult(n - 1, stirling(n - 1, k));

	cout << mult(coeff, sum);
}