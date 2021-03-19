#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mod = 1000 * 1000 * 1000 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

int mult(int a, int b) {
	return 1ll * a * b % mod;
}

int power(long long a, long long k) {
	a %= mod;
	int res = 1;
	for (; k; k >>= 1, a = mult(a, a)) {
		if (k & 1) {
			res = mult(res, a);
		}
	}
	return res;
}

const int inv2 = power(2, mod - 2);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n, m;
	cin >> n >> m;
	
	int res = 0;
	int ans = mult(n % mod, m % mod);

	m = min(n, m);
	
	long long last = 1;
	for (long long i = 1, sq = sqrt(n); i <= min(sq, m); ++i) {
		add(res, (n / i) * i % mod);
		last = i;
	}
	for (long long i = 1, sq = sqrt(n); i <= sq; ++i) {
		long long low = n / (i + 1) + 1;
		long long high = n / i;
		if (low <= last) {
			low = last + 1;
		}
		if (high > m) {
			high = m;
		}
		if (high - low < 0) {
			continue;
		}
		add(res, mult(i % mod, mult(inv2, mult((high - low + 1) % mod, (high + low) % mod))));
	}

	sub(ans, res);

	cout << ans;
}