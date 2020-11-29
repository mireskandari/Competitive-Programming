#include <bits/stdc++.h>
using namespace std;
template <typename T> int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int mn = INT_MAX;
		for (int c = 1; c <= 100; ++c) {
			int now = 0;
			int days = 0;
			for (int j = 0; j < n; ++j) {
				if (a[j] != c || now != 0) {
					now++;
					if (now == k) {
						days++;
						now = 0;
					}
				}
			}
			if (now > 0) {
				days++;
			}
			mn = min(mn, days);
		}
		cout << mn << '\n';
	}
	return 0;
}

