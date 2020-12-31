#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mod = 1000 * 1000 * 1000 + 7;

int mult(int a, int b) {
	return 1ll * a * b % mod;
}
int power(int a, int b) {
	int res = 1;
	for (; b > 0; b >>= 1, a = mult(a, a)) {
		if (b & 1) {
			res = mult(res, a);
		}
	}
	return res;
}

constexpr int mxn = 5e6 + 10;

int spf[mxn], fact[mxn], inv[mxn];

int ncr(int n, int k) {
	if (k > n || k < 0 || n < 0) {
		return 0;
	}
	return mult(fact[n], mult(inv[k], inv[n - k]));
}

int main() {
	for (int i = 2; i < mxn; ++i) {
		if (spf[i] == 0) {
			spf[i] = i;
			for (int j = 2 * i; j < mxn; j += i) {
				if (spf[j] == 0) {
					spf[j] = i;
				}
			}
		}
	}
	fact[0] = 1;
	for (int i = 1; i < mxn; ++i) {
		fact[i] = mult(fact[i - 1], i);
	}
	inv[mxn - 1] = power(fact[mxn - 1], mod - 2);
	for (int i = mxn - 1; i > 0; --i) {
		inv[i - 1] = mult(inv[i], i);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		map<int, int> factor;
		while (spf[x] > 1) {
			factor[spf[x]]++;
			x /= spf[x];
		}
		if (x > 1) {
			factor[x]++;
		}
		int ans = 1;
		for (auto &f : factor) {
			ans = mult(ans, ncr(f.second + y - 1, y - 1));
		}
		printf("%d\n", mult(ans, power(2, y - 1)));
	}
	return 0;
}

