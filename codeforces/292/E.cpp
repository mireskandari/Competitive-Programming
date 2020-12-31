#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mxn = 1e5 + 10;

int t[mxn << 2];

void push(int c, int l, int r) {
	if (t[c] != -1) {
		t[l] = t[c];
		t[r] = t[c];
		t[c] = -1;
	}
}

void update(int c, int b, int e, int u, int v, int val) {
	if (e <= u || v <= b) {
		return;
	}
	if (u <= b && e <= v) {
		t[c] = val;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	update(l, b, m, u, v, val);
	update(r, m, e, u, v, val);
}

int query(int c, int b, int e, int i) {
	if (i >= e || i < b) {
		return -1;
	}
	if (b == e - 1) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c] != -1) {
		t[l] = t[c];
		t[r] = t[c];
		t[c] = -1;
	}
	return max(query(l, b, m, i), query(r, m, e, i));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(t, -1, sizeof(t));
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		update(1, 0, n, i, i + 1, INT_MAX);
	}
	vector<array<int, 3>> qs(m);
	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			cin >> qs[m][0] >> qs[m][2] >> qs[m][1];
			--qs[m][0], --qs[m][2];
			update(1, 0, n, qs[m][2], qs[m][2] + qs[m][1], m);
		} else {
			int x;
			cin >> x;
			--x;
			int q = query(1, 0, n, x);
			if (q == INT_MAX) {
				cout << b[x] << '\n';
			} else {
				cout << a[qs[q][0] + (x - qs[q][2])] << '\n';
			}
		}
	}
	return 0;
}

