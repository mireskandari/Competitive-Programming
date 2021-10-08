#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e6 + 10;

struct Node {
	int f0, f1, fd, fi;
	bool lz;
};

Node t[N << 2];

void put(int c) {
	swap(t[c].f0, t[c].f1);
	swap(t[c].fi, t[c].fd);
	t[c].lz ^= 1;
}
	
Node merge(Node l, Node r) {
	Node res{};
	res.f0 = l.f0 + r.f0;
	res.f1 = l.f1 + r.f1;
	res.fd = max(l.fd + r.f0, l.f1 + r.fd);
	res.fi = max(l.fi + r.f1, l.f0 + r.fi);
	return res;
}

void update(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		put(c);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].lz) {
		put(l);
		put(r);
		t[c].lz = false;
	}
	if (u < m) {
		update(l, b, m, u, v);
	}
	if (v > m) {
		update(r, m, e, u, v);
	}
	t[c] = merge(t[l], t[r]);
}

int n, m;
bool a[N];

void build(int c, int b, int e) {
	if (e - b == 1) {
		t[c].fd = t[c].fi = 1;
		if (a[b]) {
			t[c].f1 = 1;
		} else {
			t[c].f0 = 1;
		}
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	t[c] = merge(t[l], t[r]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = (c == '7');
	}
	build(1, 0, n);

	while (m--) {
		string s;
		cin >> s;
		if (s == "count") {
			cout << t[1].fi << '\n';
		} else {
			int u, v;
			cin >> u >> v;
			--u;
			update(1, 0, n, u, v);
		}
	}
}