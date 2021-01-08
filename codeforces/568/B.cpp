#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mod = 1000 * 1000 * 1000 + 7;

struct mint {
	int a;

	mint(long long n = 0) : a(n % mod) {
		if (a < 0) {
			a += mod;
		}
	}
	
	mint operator-() {
		return -a + mod;
	}
	void operator+=(mint other) {
		a += other.a;
		if (a >= mod) {
			a -= mod;
		}
	}
	mint operator+(mint other) {
		other += *this;
		return other;
	}
	void operator-=(mint other) {
		a -= other.a;
		if (a < 0) {
			a += mod;
		}
	}
	mint operator-(mint other) {
		other -= *this;
		return other;
	}
	void operator*=(mint other) {
		a = 1ll * a * other.a % mod;
	}
	mint operator*(mint other) {
		other *= *this;
		return other;
	}
};

constexpr int maxn = 4e3 + 10;

mint bell[maxn];
mint comb[maxn][maxn];

mint ncr(int n, int k) {
	if (n < 0 || k < 0 || k > n) {
		return 0;
	}
	return comb[n][k];
}

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	comb[0][0] = 1;
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) {
			if (i + j == 0) {
				continue;
			}
			comb[i][j] = (i ? comb[i - 1][j] : mint(0)) + (i && j ? comb[i - 1][j - 1] : mint(0));
		}
	}
	bell[0] = 1;
	for (int i = 0; i < maxn - 1; ++i) {
		for (int j = 0; j <= i; ++j) {
			bell[i + 1] = bell[i + 1] + ncr(i, j) * bell[j];
		}
	}
	cin >> n;
	mint ans(0);
	for (int i = 1; i <= n; ++i) {
		ans += bell[n - i] * ncr(n, i);
	}
	cout << ans.a;
	return 0;
}

