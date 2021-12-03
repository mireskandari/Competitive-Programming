#include <bits/stdc++.h>
using namespace std;

const volatile auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define SHOW(a) #a << "=" << (a) << ", "

constexpr int MO = 1000 * 1000 * 1000 + 7;

void Ok(int& a) {
	if (a >= MO) a -= MO;
}
int Mult(int a, int b) {
	return 1ll * a * b % MO;
}
int Power(int a, int64_t b) {
	int res = 1;
	for (; b > 0; b >>= 1, a = Mult(a, a)) {
		if (b & 1) {
			res = Mult(res, a);
		}
	}
	return res;
}

constexpr int NN = 3010;

int fact[NN], invfact[NN];

void Init() {
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < NN; ++i) {
		fact[i] = Mult(fact[i - 1], i);
		invfact[i] = Power(fact[i], MO - 2);
	}
}
int Comb(int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	return Mult(fact[n], Mult(invfact[n - k], invfact[k]));
}

constexpr int N = 1010;
constexpr int K = 50;

int dp[K][N][N];

int main() {
	Init();
	for (int i = 0; i < N; ++i) {
		dp[1][i][i] = 1;
	}
	for (int j = 0; j < N; ++j) {
		for (int k = 1; k < N; ++k) {
			Ok(dp[1][j][k] += dp[1][j][k - 1]);
		}
	}
	for (int i = 2; i < K; ++i) {
		for (int j = 1; j < N; ++j) {
			for (int k = 1; k <= j; ++k) {
				if (j - k >= 0) {
					dp[i][j][k] = dp[i - 1][j - k][k - 1];
				}
			}
		}
		for (int j = 0; j < N; ++j) {
			for (int k = 1; k < N; ++k) {
				Ok(dp[i][j][k] += dp[i][j][k - 1]); 
			}
		}
	}
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				dp[i][j][k] = Mult(dp[i][j][k], fact[i]);
			}
		}
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		if (k >= K) {
			cout << 0 << '\n';
		} else {
			int ans = 0;
			for (int i = 0; i <= n; ++i) {
				Ok(ans += Mult(dp[k][i][N - 1], Comb(n - i, k)));
			}
			cout << ans << '\n';
		}
	}
	return 0;
}