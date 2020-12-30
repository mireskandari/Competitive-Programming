#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mod = 1000 * 1000 * 1000 + 7;

int power(int a, int b) {
	int res = 1;
	for (; b > 0; b >>= 1, a = 1ll * a * a % mod) {
		if (b & 1) {
			res = 1ll * res * a % mod;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (auto &i : a) {
			cin >> i;
		}

		vector<int> cnt(64);
		for (auto i : a) {
			int j = 0;
			while (i > 0) {
				if (i & 1) {
					cnt[j]++;
				}
				j++;
				i >>= 1;
			}
		}
		vector<int> prepcntp(64), prepcntn(64);
		for (int i = 0; i < 64; ++i) {
			prepcntp[i] = 1ll * power(2, i) * cnt[i] % mod;
			prepcntn[i] = 1ll * power(2, i) * n % mod;
		}

		vector<int> pairand(n), pairor(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 60; ++j) {
				if (((a[i] >> j) & 1)) {
					pairand[i] += prepcntp[j];
					if (pairand[i] >= mod) {
						pairand[i] -= mod;
					}
					pairor[i] += prepcntn[j];
					if (pairor[i] >= mod) {
						pairor[i] -= mod;
					}
				} else {
					pairor[i] += prepcntp[j];
					if (pairor[i] >= mod) {
						pairor[i] -= mod;
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += 1ll * pairand[i] * pairor[i] % mod;
			if (ans >= mod) {
				ans -= mod;
			}
		}
		
		cout << ans << '\n';
	}
	return 0;
}

