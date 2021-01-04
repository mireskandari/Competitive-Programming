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
		vector<array<int, 3>> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i][0] >> a[i][1];
			a[i][2] = i;
		}
		sort(a.begin(), a.end()); // by h values
		vector<int> ans(n, -1);
		int mn_w = INT_MAX, mn_w_i = -1;
		for (int i = 0, j = 0; i < n; i = j) {
			while (j < n && a[i][0] == a[j][0]) {
				++j;
			}
			for (int k = i; k < j; ++k) {
				if (mn_w < a[k][1]) {
					ans[a[k][2]] = a[mn_w_i][2];
				}
			}
			for (int k = i; k < j; ++k) {
				if (mn_w > a[k][1]) {
					mn_w = a[k][1];
					mn_w_i = k;
				}
			}
		}
		auto cpy = a;
		sort(cpy.begin(), cpy.end(), [&](const array<int, 3> &lhs, const array<int, 3> &rhs) {
			return make_tuple(lhs[1], lhs[0], lhs[2]) < make_tuple(rhs[1], rhs[0], rhs[2]);
		});
		int ptr = 0;
		int mn_h = INT_MAX, mn_h_i = -1;
		for (int i = 0; i < n; ++i) {
			while (ptr < n && cpy[ptr][1] < a[i][0]) {
				if (mn_h >= cpy[ptr][0]) {
					mn_h = cpy[ptr][0];
					mn_h_i = ptr;
				}
				++ptr;
			}
			if (mn_h < a[i][1]) {
				ans[a[i][2]] = cpy[mn_h_i][2];
			}
		}
		for (auto &i : ans) {
			cout << (i == -1 ? -1 : i + 1) << ' ';
		}
		cout << '\n';
	}
	return 0;
}

