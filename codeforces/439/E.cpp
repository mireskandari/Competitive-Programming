#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

int mult(int a, int b) {
	return 1ll * a * b % MOD;
}

constexpr int N = 1e5 + 10;

int fact[N], inv[N];
vector<int> dv[N];

int ncr(int n, int k) {
	if (k < 0 || n < k || n < 0) {
		return 0;
	}
	return mult(fact[n], mult(inv[k], inv[n - k]));
}

map<int, int> saved[N];

int solve(int f, int n) {
	if (n < f) {
		return 0;
	}
	if (saved[f].find(n) != saved[f].end()) {
		return saved[f][n];
	}
	int ans = ncr(n - 1, f - 1);
	for (auto &d : dv[n]) {
		ans -= solve(f, n / d);
		if (ans < 0) {
			ans += MOD;
		}
	}
	return saved[f][n] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			dv[j].push_back(i);
		}
	}

	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = mult(fact[i - 1], i);
	}
	{
		int res = 1;
		for (int i = fact[N - 1], k = MOD - 2; k; k >>= 1, i = mult(i, i)) {
			if (k & 1) {
				res = mult(res, i);
			}
		}
		inv[N - 1] = res;
	}
	for (int i = N - 1; i > 0; --i) {
		inv[i - 1] = mult(inv[i], i);
	}
	
	int q;
	cin >> q;
	while (q--) {
		int n, f;
		cin >> n >> f;
		cout << solve(f, n) << '\n';
	}
}