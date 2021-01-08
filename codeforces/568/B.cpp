#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mod = 1000 * 1000 * 1000 + 7;

int add(int a, int b) {
	a += b;
	if (a >= mod) { 
		a -= mod; 
	}
	if (a < 0) { 
		a += mod; 
	}
	return a;
}
int mult(int a, int b) {
	return 1ll * a * b % mod;
}

constexpr int maxn = 4e3 + 10;

int bell[maxn];
int comb[maxn][maxn];

int ncr(int n, int k) {
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
			comb[i][j] = add((i ? comb[i - 1][j] : 0), (i && j ? comb[i - 1][j - 1] : 0));
		}
	}
	bell[0] = 1;
	for (int i = 0; i < maxn - 1; ++i) {
		for (int j = 0; j <= i; ++j) {
			bell[i + 1] = add(bell[i + 1], mult(ncr(i, j), bell[j]));
		}
	}
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = add(ans, mult(bell[n - i], ncr(n, i)));
	}
	cout << ans;
	return 0;
}

