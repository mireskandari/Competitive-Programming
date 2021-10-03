#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 3e5 + 10;

struct Node {
	int mx, mxi, lz;
};

Node t[N << 2];

void apply(int c, int x) {
	t[c].mx += x;
	t[c].lz += x;
}

void build(int c, int b, int e) {
	t[c].mxi = b;
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1;
	build(c << 1, b, m);
	build(c << 1 | 1, m, e);
}

void update(int c, int b, int e, int u, int v, bool z) {
	if (u <= b && e <= v) {
		apply(c, z ? 1 : -1);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].lz != 0) {
		apply(l, t[c].lz);
		apply(r, t[c].lz);
		t[c].lz = 0;
	}
	if (u < m) {
		update(l, b, m, u, v, z);
	}
	if (v > m) {
		update(r, m, e, u, v, z);
	}
	t[c].mx = max(t[l].mx, t[r].mx);
	t[c].mxi = t[c].mx == t[l].mx ? t[l].mxi : t[r].mxi;
}

pair<int, int> query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return {t[c].mx, t[c].mxi};
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	pair<int, int> ret = {0, 0};
	if (u < m) {
		ret = query(l, b, m, u, v);
	}
	if (v > m) {
		auto tmp = query(r, m, e, u, v);
		ret.first = max(ret.first, tmp.first);
		ret.second = ret.first == tmp.first ? tmp.second : ret.second;
	}
	return ret;
}

int n, l[N], r[N], v[N];
vector<pair<int, int>> s[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	build(1, 0, N);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> v[i] >> r[i];
		s[v[i]].push_back({l[i], v[i]});
		s[r[i] + 1].push_back({-l[i], -v[i]});
	}
	
	pair<pair<int, int>, int> mx;
	for (int i = 0; i < N; ++i) {
		for (auto &p : s[i]) {
			if (p.first < 0) {
				update(1, 0, N, -p.first, -p.second + 1, false);
			}
		}
		for (auto &p : s[i]) {
			if (p.first > 0) {
				update(1, 0, N, p.first, p.second + 1, true);
			}
		}
		mx = max(mx, make_pair(query(1, 0, N, 0, N), i));
	}
	
	cout << mx.first.first << '\n';

	int ll = mx.first.second, rr = mx.second;
	for (int i = 0; i < n; ++i) {
		if (l[i] <= ll && rr <= r[i] && v[i] >= ll && v[i] <= rr) {
			cout << i + 1 << ' ';
		}
	}
}