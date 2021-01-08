#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	vector<vector<pair<int, bool>>> t(25, vector<pair<int, bool>>(n << 2));
	auto push = [&](int i, int c, int b, int m, int e) {
		if (t[i][c].second) {
			t[i][c << 1].second ^= 1;
			t[i][c << 1].first = (m - b) - t[i][c << 1].first;
			t[i][c << 1 | 1].second ^= 1;
			t[i][c << 1 | 1].first = (e - m) - t[i][c << 1 | 1].first;
			t[i][c].second = false;
		}
	};
	function<void(int, int, int, int, int, int)> update = [&](int i, int c, int b, int e, int u, int v) {
		if (e <= u || v <= b) {
			return;
		}
		if (u <= b && e <= v) {
			t[i][c].first = (e - b) - t[i][c].first;
			t[i][c].second ^= 1;
			return;
		}
		int m = (b + e) >> 1;
		push(i, c, b, m, e);
		update(i, c << 1, b, m, u, v);
		update(i, c << 1 | 1, m, e, u, v);
		t[i][c].first = t[i][c << 1].first + t[i][c << 1 | 1].first;
	};
	function<int(int, int, int, int, int, int)> query = [&](int i, int c, int b, int e, int u, int v) {
		if (e <= u || v <= b) {
			return 0;
		}
		if (u <= b && e <= v) {
			return t[i][c].first;
		}
		int m = (b + e) >> 1;
		push(i, c, b, m, e);
		return query(i, c << 1, b, m, u, v) + query(i, c << 1 | 1, m, e, u, v);
	};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 25; ++j) {
			if (a[i] >> j & 1) {
				update(j, 1, 0, n, i, i + 1);
			}
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int u, v;
			cin >> u >> v;
			--u;
			long long ans = 0;
			for (int i = 0; i < 25; ++i) {
				ans += (1ll << i) * query(i, 1, 0, n, u, v);
			}
			cout << ans << '\n';
		} else {
			int u, v, x;
			cin >> u >> v >> x;
			--u;
			for (int i = 0; i < 25; ++i) {
				if (x >> i & 1) {
					update(i, 1, 0, n, u, v);
				}
			}
		}
	}
	return 0;
}

