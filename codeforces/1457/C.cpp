#include <bits/stdc++.h>
using namespace std;
template <typename T> int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, p, k;
		cin >> n >> p >> k;
		--p;
		vector<bool> a(n);
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;
			a[i] = c - '0';
		}
		int x, y;
		cin >> x >> y;
		vector<vector<int>> pref(k), bitches(k);
		for (int i = 0; i < n; ++i) {
			if (a[i]) {
				pref[i % k].push_back(i);
			}
			bitches[i % k].push_back(i);
		}
		int mn = INT_MAX;
		for (int i = 0; i < n - p; ++i) {
			int md = (i + p) % k;
			auto q = lower_bound(pref[md].begin(), pref[md].end(), i + p);
			auto r = lower_bound(bitches[md].begin(), bitches[md].end(), i + p);
			int must = bitches[md].end() - r;
			int has = pref[md].end() - q;
			int need = must - has;
			mn = min(mn, need * x + i * y);
		}
		cout << mn << '\n';
	}
	return 0;
}

