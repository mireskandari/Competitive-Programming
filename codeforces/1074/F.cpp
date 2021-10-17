#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10, LG = 20;

struct Node {
	int lz, mn, cnt;
};

Node t[N << 2];

void apply(int c, int x) {
	t[c].mn += x;
	t[c].lz += x;
}

void build(int c, int b, int e) {
	t[c].cnt = e - b;
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
}

void update(int c, int b, int e, int u, int v, int x) {
	if (e <= u || v <= b) {
		return;
	}
	if (u <= b && e <= v) {
		apply(c, x);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].lz != 0) {
		apply(l, t[c].lz);
		apply(r, t[c].lz);
		t[c].lz = 0;
	}
	update(l, b, m, u, v, x);
	update(r, m, e, u, v, x);
	t[c].mn = min(t[l].mn, t[r].mn);
	t[c].cnt = (t[l].mn == t[c].mn ? t[l].cnt : 0) + (t[r].mn == t[c].mn ? t[r].cnt : 0);
}

int n, q, tin[N], tout[N], timer, par[LG][N], dep[N];
vector<int> g[N];
set<pair<int, int>> st;

void dfs(int v, int p) {
	tin[v] = timer++;
	par[0][v] = p;
	for (int i = 1; i < LG; ++i) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}
	for (auto &u : g[v]) {
		if (u != p) {
			dep[u] = dep[v] + 1;
			dfs(u, v);
		}
	}
	tout[v] = timer;
}

bool is_par(int p, int v) {
	return tin[p] <= tin[v] && tout[v] <= tout[p];
}

int get_par(int v, int k) {
	for (int i = 0; i < LG; ++i) {
		if ((k >> i) & 1) {
			v = par[i][v];
		}
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	build(1, 0, n);
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	
	dfs(0, 0);
	build(1, 0, n);

	while (q--) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		if (v < u) {
			swap(u, v);
		}
		bool had = st.find({u, v}) != st.end();
		if (had) {
			st.erase({u, v});
		} else {
			st.insert({u, v});
		}
		int coeff = had ? -1 : +1;
		if (is_par(u, v)) {
			swap(u, v);
		}
		if (is_par(v, u)) {
			int tmp = get_par(u, dep[u] - dep[v] - 1);
			update(1, 0, n, tin[tmp], tout[tmp], coeff);
			update(1, 0, n, tin[u], tout[u], -coeff);
		} else {
			update(1, 0, n, 0, n, coeff);
			update(1, 0, n, tin[v], tout[v], -coeff);
			update(1, 0, n, tin[u], tout[u], -coeff);
		}
		cout << (t[1].mn == 0 ? t[1].cnt : 0) << '\n';
	}
}