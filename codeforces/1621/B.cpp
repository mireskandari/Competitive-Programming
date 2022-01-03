#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> l(n), r(n), c(n);
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> r[i] >> c[i];
		}
		int ind_min = 0, ind_max = 0;
		int cost = c[0];
		vector<int> ans(n, INT_MAX);
		ans[0] = cost;
		for (int i = 1; i < n; ++i) {
			int last = r[ind_max] - l[ind_min];
			if (r[ind_max] < r[i]) {
				ind_max = i;
			}
			if (l[ind_min] > l[i]) {
				ind_min = i;
			}
			if (r[i] - l[i] == r[ind_max] - l[ind_min]) {
				ans[i] = c[i];
			}
			if (last == r[ind_max] - l[ind_min]) {
				ans[i] = min(ans[i], ans[i - 1]);
			}
		}
		ind_min = 0, ind_max = 0;
		for (int i = 0; i < n; ++i) {
			if (r[ind_max] < r[i] || (r[ind_max] == r[i] && c[ind_max] > c[i])) {
				ind_max = i;
			}
			if (l[ind_min] > l[i] || (l[ind_min] == l[i] && c[ind_min] > c[i])) {
				ind_min = i;
			}
			ans[i] = min(ans[i], c[ind_min] + c[ind_max]);
		}
		for (int i = 0; i < n; ++i) {
			cout << ans[i] << '\n';
		}
	}
}