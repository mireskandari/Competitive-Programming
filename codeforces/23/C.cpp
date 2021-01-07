#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		n = 2 * n - 1;
		vector<tuple<int, int, int>> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> get<0>(a[i]) >> get<1>(a[i]);
			get<2>(a[i]) = i;
		}
		sort(a.rbegin(), a.rend());
		long long sum_odd = 0, sum_even = 0;
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				sum_odd += get<1>(a[i]);
			} else {
				sum_even += get<1>(a[i]);
			}
		}
		cout << "YES\n";
		if (sum_even >= sum_odd) {
			for (int i = 0; i < n; ++i) {
				if (!(i & 1)) {
					cout << get<2>(a[i]) + 1 << ' ';
				}
			}
		} else {
			for (int i = 0; i < n; ++i) {
				if (i & 1) {
					cout << get<2>(a[i]) + 1 << ' ';
				}
			}
			cout << get<2>(a[0]) + 1;
		}
		cout << '\n';
	}
	return 0;
}