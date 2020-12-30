#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

struct segtree {
	struct node {
		int g = 0, mn = INT_MAX;
	};
	vector<node> t;

	segtree(int n) : t(n << 2) {}
	
	void pull(node &res, node l, node r) {
		res.g = __gcd(l.g, r.g);
		res.mn = min(l.mn, r.mn);
	}

	void build(int c, int b, int e, vector<int> &a) {
		if (e <= b) {
			return;
		}
		if (b == e - 1) {
			t[c].g = a[b];
			t[c].mn = a[b];
			return;
		}
		int m = (b + e) >> 1, l = c << 1, r = l | 1;
		build(l, b, m, a);
		build(r, m, e, a);
		pull(t[c], t[l], t[r]);
	}

	node query(int c, int b, int e, int u, int v) {
		if (v <= b || e <= u) {
			return node{};
		}
		if (u <= b && e <= v) {
			return t[c];
		}
		int m = (b + e) >> 1, l = c << 1, r = l | 1;
		node res{};
		pull(res, query(l, b, m, u, v), query(r, m, e, u, v));
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}

	map<int, vector<int>> pos;
	for (int i = 0; i < n; ++i) {
		pos[a[i]].push_back(i);
	}
	segtree st(n);
	st.build(1, 0, n, a);

	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		--l;
		auto res = st.query(1, 0, n, l, r);
		if (res.g < res.mn) {
			cout << (r - l) << '\n';
		} else {
			auto v = lower_bound(pos[res.g].begin(), pos[res.g].end(), r);
			auto u = lower_bound(pos[res.g].begin(), pos[res.g].end(), l);
			cout << (r - l) - (v - u) << '\n';
		}
	}
	return 0;
}

