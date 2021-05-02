#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int maxn = 410;
int mod;

struct mint {
	int a;
	mint(long long n = 0) : a(n) {} // do things if needed
	
	mint &operator+=(mint other) {
		if ((a += other.a) >= mod) {
			a -= mod;
		}
		return *this;
	}
	mint &operator-=(mint other) {
		if ((a -= other.a) < 0) {
			a += mod;
		}
		return *this;
	}
	mint &operator*=(mint other) {
		a = 1ll * a * other.a % mod;
		return *this;
	}
	mint operator+(mint other) const {
		return (mint(*this) += other);
	}
	mint operator-(mint other) const {
		return (mint(*this) -= other);
	}
	mint operator*(mint other) const {
		return (mint(*this) *= other);
	}
	mint operator-() const {
		return mint(-a + mod);
	}
};

int n;
mint dp[maxn][maxn], ncr[maxn][maxn];

mint comb(int k, int r) {
	if (k < 0 || r < 0 || k < r) {
		return 0;
	}
	return ncr[k][r];
}

mint pow2[maxn];

int main() {
	scanf("%d%d", &n, &mod);
	ncr[0][0] = 1;
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) {
			if (i + j != 0) {
				ncr[i][j] = (i ? ncr[i - 1][j] : mint(0)) + (i && j ? ncr[i - 1][j - 1] : mint(0));
			}
		}
	}
	pow2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pow2[i] = pow2[i - 1] * mint(2);
	}
	dp[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = pow2[i - 1];
		for (int j = 1; j <= i; ++j) {
			for (int k = 1; k <= i - j; ++k) {
				dp[i][j] += pow2[k - 1] * (i - k - 1 >= 0 ? dp[i - k - 1][j - 1] : mint(0)) * comb(i - j, k);
			}
		}
	}

	mint sum = 0;
	for (int j = 0; j <= n; ++j) {
		sum += dp[n][j];
	}
	cout << sum.a;
}
