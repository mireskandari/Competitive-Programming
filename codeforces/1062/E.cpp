#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10, LG = 20;

struct Node {
	int mxi, mni;
	
	Node() : mxi(100001), mni(100002) {}
};

Node t[N << 2];

int n, q, tin[N], tout[N], timer, dep[N], par[LG][N];
vector<int> g[N];

Node pull(Node l, Node r) {
	if (tin[r.mni] < tin[l.mni]) {
		swap(r.mni, l.mni);
	}
	if (tout[r.mxi] > tout[l.mxi]) {
		swap(r.mxi, l.mxi);
	}
	return l;
}

void build(int c, int b, int e) {
	if (e - b == 1) {
		t[c].mni = t[c].mxi = b;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	t[c] = pull(t[l], t[r]);
}

Node query(int c, int b, int e, int u, int v) {
	if (e <= u || v <= b) {
		return Node();
	}
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	return pull(query(l, b, m, u, v), query(r, m, e, u, v));
}

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

int get_par(int v, int k) {
	for (int i = 0; i < LG; ++i) {
		if ((k >> i) & 1) {
			v = par[i][v];
		}
	}
	return v;
}

int lca(int v, int u) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	u = get_par(u, dep[u] - dep[v]);
	if (v == u) {
		return v;
	}
	for (int i = LG - 1; i >= 0; --i) {
		if (par[i][v] != par[i][u]) {
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	tin[100002] = 1e9;
	tout[100001] = -1e9;

	for (int i = 1; i < n; ++i) {
		int v;
		cin >> v;
		g[i].push_back(--v);
		g[v].push_back(i);
	}
	
	dfs(0, 0);
	build(1, 0, n);

	while (q--) {
		int l, r;
		cin >> l >> r;
		--l;
		auto ret = query(1, 0, n, l, r);
		int l1, l2;
		{
			auto tmp = pull(query(1, 0, n, l, ret.mni), query(1, 0, n, ret.mni + 1, r));
			l1 = lca(tmp.mni, tmp.mxi);
		}
		{
			auto tmp = pull(query(1, 0, n, l, ret.mxi), query(1, 0, n, ret.mxi + 1, r));
			l2 = lca(tmp.mni, tmp.mxi);
		}
		if (dep[l2] > dep[l1]) {
			swap(l2, l1);
			swap(ret.mni, ret.mxi);
		}
		cout << ret.mni + 1 << ' ' << dep[l1] << '\n';
	}
}