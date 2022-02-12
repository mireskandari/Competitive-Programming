#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int n, que;
vector<int> g[N];
int dep[N], par[20][N];

void prep(int v, int p) {
	for (auto &u : g[v]) {
		if (u != p) {
			par[0][u] = v;
			for (int i = 1; i < 20; ++i) {
				par[i][u] = par[i - 1][par[i - 1][u]];
			}
			dep[u] = dep[v] + 1;
			prep(u, v);
		}
	}
}


int getpar(int v, int k) {
	for (int i = 0; i < 20; ++i) {
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
	u = getpar(u, dep[u] - dep[v]);
	if (u == v) {
		return u;
	}
	for (int i = 19; i >= 0; --i) {
		if (par[i][v] != par[i][u]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][v];
}

int color[N];
int mn[N][2];
int cpar[N];
int sz[N];
bool used[N];

void cprep(int v, int p) {
	sz[v] = 1;
	for (auto &u : g[v]) {
		if (u != p && !used[p]) {
			cprep(u, v);
			sz[v] += sz[u];
		}
	}
}

int centroid(int v, int p, int m) {
	bool good = true;
	for (auto &u : g[v]) {
		if (u != p && !used[u]) {
			int ret = centroid(u, v, m);
			if (~ret) {
				return ret;
			}
			if (sz[u] > m / 2) {
				good = false;
			}
		}
	}
	if (m - sz[v] > m / 2) {
		good = false;
	}
	return good ? v : -1;
}

void add(int v) {
	color[v] = true;
	int u = v;
	int tmp = -1;
	while (u != -1) {
		assert(tmp != u);
		int dist = dep[v] + dep[u] - 2 * dep[lca(u, v)];
		if (dist < mn[u][0]) {
			mn[u][1] = mn[u][0];
			mn[u][0] = dist;
		} else if (mn[u][1] > dist) {
			mn[u][1] = dist;
		}
		tmp = u;
		u = cpar[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> que;
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	queue<pair<int, int>> q;
	q.push({0, -1});
	while (!q.empty()) {
		int v = q.front().first, cp = q.front().second;
		q.pop();
		cprep(v, -1);
		int c = centroid(v, -1, sz[v]);
		cpar[c] = cp;
		used[c] = true;
		for (auto &u : g[c]) {
			if (!used[u]) {
				q.push({u, c});
			}
		}
	}
	
	prep(0, -1);

	for (int i = 0; i < n; ++i) {
		mn[i][0] = mn[i][1] = 1e9;
	}

	add(0);

	while (que--) {
		int op, v;
		cin >> op >> v;
		--v;
		if (op == 1) {
			add(v);
		} else {
			int u = v;
			int ans = color[v] ? 0 : (int) 1e9;
			int tmp = -1;
			while (u != -1) {
				assert(u != tmp);
				int dist = dep[v] + dep[u] - 2 * dep[lca(u, v)];
				if (color[v] && dist == mn[u][0]) {
					ans = min(dist + mn[u][1], ans);
				} else {
					ans = min(dist + mn[u][0], ans);
				}
				tmp = u;
				u = cpar[u];
			}
			cout << ans << '\n';
		}
	}
}