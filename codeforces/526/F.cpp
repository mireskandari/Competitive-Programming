#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 3e5 + 10;

struct Node {
	int mn, cnt, lz;
};

Node t[N << 2];

void apply(int c, int x) {
	t[c].mn += x;
	t[c].lz += x;
}

void push(int c, int l, int r) {
	if (t[c].lz != 0) {
		apply(l, t[c].lz);
		apply(r, t[c].lz);
		t[c].lz = 0;
	}
}

void build(int c, int b, int e) {
	t[c].cnt = e - b;
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1;
	build(c << 1, b, m);
	build(c << 1 | 1, m, e);
}

void update(int c, int b, int e, int u, int v, int x) {
	if (v <= b || e <= u) {
		return;
	}
	if (u <= b && e <= v) {
		apply(c, x);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	update(l, b, m, u, v, x);
	update(r, m, e, u, v, x);
	t[c].mn = min(t[l].mn, t[r].mn);
	t[c].cnt = (t[l].mn == t[c].mn ? t[l].cnt : 0) +
		(t[r].mn == t[c].mn ? t[r].cnt : 0);
}

int query(int c, int b, int e, int u, int v) {
	if (v <= b || e <= u) {
		return 0;
	}
	if (u <= b && e <= v) {
		return (t[c].mn == 0 ? t[c].cnt : 0);
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	return query(l, b, m, u, v) + query(r, m, e, u, v);
}

int n, a[N];
vector<int> mns, mxs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	build(1, 0, n);

	for (int i = 0; i < n; ++i) {
		int r, c;
		cin >> r >> c;
		a[--r] = --c;
	}
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		update(1, 0, n, 0, i, -1);

		while (!mns.empty() && a[mns.back()] > a[i]) {
			int x = mns.back();
			mns.pop_back();
			update(1, 0, n, (mns.empty() ? -1 : mns.back()) + 1, x + 1, a[x] - a[i]);
		}
		mns.push_back(i);
		while (!mxs.empty() && a[mxs.back()] < a[i]) {
			int x = mxs.back();
			mxs.pop_back();
			update(1, 0, n, (mxs.empty() ? -1 : mxs.back()) + 1, x + 1, a[i] - a[x]);
		}
		mxs.push_back(i);
		
		ans += query(1, 0, n, 0, i + 1);
	}

	cout << ans;
}