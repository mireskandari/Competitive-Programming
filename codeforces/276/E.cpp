#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 1e5 + 10;

struct Seg {
	int sz;
	vector<int> t;

	Seg() {}

	Seg(int n) : sz(n), t(n << 2) {}

	void update(int c, int b, int e, int u, int x) {
		if (u < b || e <= u) {
			return;
		}
		if (e - b == 1) {
			t[c] += x;
			return;
		}
		int m = (e + b) >> 1, l = c << 1, r = l | 1;
		update(l, b, m, u, x);
		update(r, m, e, u, x);
		t[c] = t[l] + t[r];
	}

	int query(int c, int b, int e, int u, int v) {
		if (e <= u || v <= b) {
			return 0;
		}
		if (u <= b && e <= v) {
			return t[c];
		}
		int m = (e + b) >> 1, l = c << 1, r = l | 1;
		return query(l, b, m, u, v) + query(r, m, e, u, v);
	}

	void update2(int l, int r, int x) {
		if (l > r || l >= sz) {
			return;
		}
		r = min(sz - 1, r);
		if (r < sz - 1) {
			update(1, 0, sz, r + 1, -x);
		}
		update(1, 0, sz, l, x);
	}

	int query2(int i) {
		return query(1, 0, sz, 0, i + 1);
	}
};

Seg t[N];
vector<int> g[N];

bool mark[N];
int where[N], idx[N];
int gp[N];
int gpn;
int n, q;

void dfs(int v, int p) {
	gpn = max(gpn, p + 1);
	if (~p) {
		idx[v] = gp[p];
		where[v] = p;
		gp[p]++;
	}
	mark[v] = true;

	int i = 0;
	for (auto &u : g[v]) {
		if (!mark[u]) {
			dfs(u, ~p ? p : i);
			++i;
		}
	}
}

int one_node;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	dfs(0, -1);
	
	for (int i = 0; i < gpn; ++i) {
		t[i] = Seg(gp[i]);
	}
	t[gpn] = Seg(N);

	while (q--) {
		int op;
		cin >> op;
		
		if (op == 0) {
			int v, x, d;
			cin >> v >> x >> d;
			--v;

			if (v == 0) {
				one_node += x;
				t[gpn].update2(0, d - 1, x);
				continue;
			}
			
			int group = where[v], dist = idx[v];
			if (d == dist + 1) {
				//cerr << "ONE\n";
				one_node += x;
				t[group].update2(0, dist + d, x);
			} else if (d <= dist) {
				//cerr << "TWO\n";
				t[group].update2(dist - d, dist + d, x);
			} else {
				//cerr << "THREE\n";
				one_node += x;
				int rm = d - dist - 2;
				//cerr << rm << '\n';
				t[group].update2(rm + 1, dist + d, x);
				t[gpn].update2(0, rm, x);
			}
		} else {
			int v;
			cin >> v;
			--v;
			
			if (v == 0) {
				cout << one_node << '\n';
				continue;
			}

			int group = where[v], dist = idx[v];
			cout << t[group].query2(dist) + t[gpn].query2(dist) << '\n';
		}
	}
}