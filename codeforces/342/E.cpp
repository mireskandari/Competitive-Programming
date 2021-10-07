#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10, SQ = 320, LG = 21;

int n, m, bst[N];
vector<int> g[N];
bool mark[N];
vector<int> qs;
int par[LG][N], dep[N];

void prep(int v, int p) {
	par[0][v] = p;
	for (int i = 1; i < LG; ++i) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}

	for (auto &u : g[v]) {
		if (u != p) {
			dep[u] = dep[v] + 1;
			prep(u, v);
		}
	}
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
	if (dep[v] > dep[u]) {
		swap(u, v);
	}
	u = get_par(u, dep[u] - dep[v]);
	if (u == v) {
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

int dist(int v, int u) {
	int l = lca(v, u);
	return dep[v] - dep[l] + dep[u] - dep[l];
}

int d[N];

void bfs() {
	queue<int> q;
	memset(d, 0x3f, sizeof(int) * n);
	for (auto &v : qs) {
		q.push(v);
		d[v] = 0;
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto &u : g[v]) {
			if (d[u] == 0x3f3f3f3f) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		bst[i] = min(bst[i], d[i]);
	}
}

void recalc() {
	bfs();
	qs.clear();
	memset(mark, 0, sizeof(bool) * n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	prep(0, 0);
	for (int i = 0; i < n; ++i) {
		bst[i] = dist(0, i);
	}

	while (m--) {
		int op, v;
		cin >> op >> v;
		--v;
		if (op == 1) {
			qs.push_back(v);
			if ((int) qs.size() == SQ) {
				recalc();
			}
		} else {
			int ans = bst[v];
			for (auto &u : qs) {
				ans = min(ans, dist(u, v));
			}
			cout << ans << '\n';
		}
	}
}