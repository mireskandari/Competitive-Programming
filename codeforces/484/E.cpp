#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

struct Node {
	int p, s, mx, size;
 
	Node(int a = 0, int u = 0, int v = 0) : p(a), s(a), mx(a), size(v - u) {}
};
 
Node t[N << 2];
 
void build(int c, int b, int e) {
	t[c].p = t[c].s = t[c].mx = 0;
	t[c].size = e - b;
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1;
	build(c << 1, b, m);
	build(c << 1 | 1, m, e);
}
 
void pull(Node &c, Node l, Node r, bool change) {
	c.p = l.p + (l.p == l.size ? r.p : 0);
	c.s = r.s + (r.s == r.size ? l.s : 0);
	if (change) {
		c.size = l.size + r.size;
	}
	c.mx = max({l.mx, r.mx, l.s + r.p});
}
 
void update(int c, int b, int e, int i) {
	if (e - b == 1) {
		t[c].p = 1;
		t[c].s = 1;
		t[c].mx = 1;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (i < m) {
		update(l, b, m, i);
	} else {
		update(r, m, e, i);
	}
	pull(t[c], t[l], t[r], false);
}
 
Node query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	Node ret(0);
	if (u < m) {
		if (v > m) {
			pull(ret, query(l, b, m, u, v), query(r, m, e, u, v), true);
		} else {
			ret = query(l, b, m, u, v);
		}
	} else {
		ret = query(r, m, e, u, v);
	}
	return ret;
}

void show(int c, int b, int e) {
	cerr << b << ' ' << e << ' ' << t[c].p << ' ' << t[c].s << ' ' << t[c].mx << '\n';
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1;
	show(c << 1, b, m);
	show(c << 1 | 1, m, e);
}

int n, m, h[N], low[N], mid[N], high[N];
tuple<int, int, int> qq[N];
vector<int> sweep[N];
int tmpp[N], tmp2[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		tmpp[i] = h[i];
		tmp2[i] = i;
	}
	sort(tmp2, tmp2 + n, [&](int l, int r) {
		return h[l] < h[r];
	});
	sort(tmpp, tmpp + n);
	
	cin >> m;
	/*for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		update(1, 0, n, a);
		show(1, 0, n);
		cerr << "\n\n\n";
	}*/

	for (int i = 0; i < m; ++i) {
		cin >> get<0>(qq[i]) >> get<1>(qq[i]) >> get<2>(qq[i]);
		--get<0>(qq[i]);
		low[i] = 0, high[i] = n - 1;
	}
	
	for (int l = 0; l < 23; ++l) {
		//cerr << "KIRESAG\n";
		fill(sweep, sweep + N, vector<int>());
		build(1, 0, n);
		for (int i = 0; i < m; ++i) {
			mid[i] = (low[i] + high[i] + 1) >> 1;
			sweep[mid[i]].push_back(i);
		}
		for (int i = n - 1; i >= 0; --i) {
			update(1, 0, n, tmp2[i]);
			//show(1, 0, n);
			//cerr << "\n\n\n";
			for (auto &q : sweep[i]) {
				//cerr << q << ' ' << query(1, 0, n, get<0>(qq[q]), get<1>(qq[q])).mx << '\n';
				if (query(1, 0, n, get<0>(qq[q]), get<1>(qq[q])).mx >= get<2>(qq[q])) {
					low[q] = i;
				} else {
					high[q] = i - 1;
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		assert(low[i] == high[i]);
		cout << tmpp[low[i]] << '\n';
	}
}