#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int n, k;
vector<int> g[N];
int tin[N], dep[N], par[20][N], timer;

void dfs(int v, int p) {
	tin[v] = timer++;
	par[0][v] = p;
	for (int i = 1; i < 20; ++i) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}
	for (auto &u : g[v]) {
		if (u != p) {
			dep[u] = dep[v] + 1;
			dfs(u, v);
		}
	}
}

int lca(int v, int u) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	int k = dep[u] - dep[v];
	for (int i = 0; i < 20; ++i) {
		if ((k >> i) & 1) {
			u = par[i][u];
		}
	}
	if (u == v) {
		return v;
	}
	for (int i = 19; i >= 0; --i) {
		if (par[i][v] != par[i][u]) {
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

int dist(int v, int u) {
	return dep[v] + dep[u] - 2 * dep[lca(u, v)];
}

set<pair<int, int>> st;
int cur;

void modify_node(int v, bool add) {
	st.insert({tin[v], v});
	auto p = st.find({tin[v], v});
	int bf, af;
	if (p == prev(st.end())) {
		af = st.begin()->second;
	} else {
		af = next(p)->second;
	}
	if (p == st.begin()) {
		bf = st.rbegin()->second;
	} else {
		bf = prev(p)->second;
	}
	cur += (add ? 1 : -1) * (dist(v, bf) + dist(v, af) - dist(af, bf));
	if (!add) {
		st.erase({tin[v], v});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	dfs(0, 0);
	
	st.insert({tin[0], 0});
	int mx = 1;
	for (int l = 0, r = 1; l < n; ++l) {
		if (l) {
			modify_node(l - 1, false);
		}
		if (r == l) {
			st.insert({tin[l], l});
			++r;
		}
		while (r < n) {
			modify_node(r, true);
			if ((cur / 2) + 1 > k) {
				modify_node(r, false);
				break;
			}
			++r;
		}
		mx = max(mx, r - l);
	}
	
	cout << mx;
}