#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

struct Node {
	int mx;
	long long sum;
};

int n, m, a[N];
Node t[N << 2];

void build(int c, int b, int e) {
	if (e - b == 1) {
		t[c].mx = t[c].sum = a[b];
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	t[c].sum = t[l].sum + t[r].sum;
	t[c].mx = max(t[l].mx, t[r].mx);
}

void update_mod(int c, int b, int e, int u, int v, int x) {
	if (u >= e || v <= b || t[c].mx < x) {
		return;
	}
	if (e - b == 1) {
		t[c].mx = t[c].mx % x;
		t[c].sum = t[c].mx;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	update_mod(l, b, m, u, v, x);
	update_mod(r, m, e, u, v, x);
	t[c].mx = max(t[l].mx, t[r].mx);
	t[c].sum = t[l].sum + t[r].sum;
}

long long query(int c, int b, int e, int u, int v) {
	if (u >= e || v <= b) {
		return 0;
	}
	if (u <= b && e <= v) {
		return t[c].sum;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	return query(l, b, m, u, v) + query(r, m, e, u, v);
}

void update(int c, int b, int e, int i, int x) {
	if (i >= e || i < b) {
		return;
	}
	if (e - b == 1) {
		t[c].mx = x;
		t[c].sum = x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	update(l, b, m, i, x);
	update(r, m, e, i, x);
	t[c].sum = t[l].sum + t[r].sum;
	t[c].mx = max(t[l].mx, t[r].mx);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	build(1, 0, n);

	while (m--) {
		int op, u;
		cin >> op >> u;
		--u;
		if (op == 1) {
			int v;
			cin >> v;
			cout << query(1, 0, n, u, v) << '\n';
		} else if (op == 2) {
			int v, x;
			cin >> v >> x;
			update_mod(1, 0, n, u, v, x);
		} else {
			int x;
			cin >> x;
			update(1, 0, n, u, x);
		}
	}
}