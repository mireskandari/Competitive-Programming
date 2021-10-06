#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 5e5 + 10;

int n, q, a[N], t[N << 2];

void update(int c, int b, int e, int u, int x) {
	if (e - b == 1) {
		t[c] = x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (u < m) {
		update(l, b, m, u, x);
	}
	if (u >= m) {
		update(r, m, e, u, x);
	}
	t[c] = __gcd(t[l], t[r]);
}

int bad_l, bad_r;

int query(int c, int b, int e, int u, int v, int x) {
	if (u >= e || v <= b) {
		return 0;
	}
	if (u <= b && e <= v) {
		if (t[c] % x != 0) {
			bad_l = b;
			bad_r = e;
			return c;
		}
		return 0;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	int ll = query(l, b, m, u, v, x);
	int rr = query(r, m, e, u, v, x);
	if (ll == -1 || rr == -1) {
		return -1;
	}
	if (ll != 0 && rr != 0) {
		return -1;
	}
	return ll ^ rr;
}

bool cool(int c, int b, int e, int x) {
	if (e - b == 1) {
		return true;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	bool gl = t[l] % x == 0, gr = t[r] % x == 0;
	if (!gl && !gr) {
		return false;
	}
	if (!gl) {
		return cool(l, b, m, x);
	}
	return cool(r, m, e, x);
}

void build(int c, int b, int e) {
	if (e - b == 1) {
		t[c] = a[b];
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	t[c] = __gcd(t[l], t[r]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	build(1, 0, n);
	
	cin >> q;
	while (q--) {
		int op, u, v;
		cin >> op >> u >> v;
		--u;
		if (op == 1) {
			int x;
			cin >> x;
			int ret = query(1, 0, n, u, v, x);
			if (ret == -1) {
				cout << "NO\n";
			} else if (ret == 0) {
				cout << "YES\n";
			} else {
				cout << (cool(ret, bad_l, bad_r, x) ? "YES\n" : "NO\n");
			}
		} else {
			update(1, 0, n, u, v);
		}
	}
}