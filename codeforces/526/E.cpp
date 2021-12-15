#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	vector<int> a(2 * n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> pref(2 * n);
	pref[0] = a[0];
	for (int i = 1; i < 2 * n; ++i) {
		if (i >= n) {
			a[i] = a[i - n];
		}
		pref[i] = pref[i - 1] + a[i];
	}

	while (q--) {
		long long x;
		cin >> x;
		
		if (pref[n - 1] <= x) {
			cout << 1 << '\n';
		} else {
			vector<int> best(2 * n);
			while (pref[best[0] + 1] <= x) {
				++best[0];
			}
			int mn = 0;
			for (int i = 1; i < 2 * n; ++i) {
				best[i] = best[i - 1];
				while (best[i] + 1 < 2 * n && pref[best[i] + 1] - pref[i - 1] <= x) {
					++best[i];
				}
				if (i < n && best[mn] - mn > best[i] - i) {
					mn = i;
				}
			}
			int ans = n;
			for (int i = max(0, mn - 1); i < min(best[mn] + 2, 2 * n); ++i) {
				int j = i;
				if (j >= n) {
					j -= n;
				}
				int now = 0, tmp = j;
				while (j < tmp + n) {
					++now;
					j = best[j] + 1;
				}
				ans = min(ans, now);
			}
			cout << ans << '\n';
		}
	}
}