#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10, MOD = 1000 * 1000 * 1000 + 7;

int n, tin[N], tout[N], timer, sz[N];
vector<pair<int, int>> g[N];
vector<int> shit[N];

int par[20][N], dep[N], dist[N];

void prep(int v, int p) {
	tin[v] = timer++;
	for (auto &e : g[v]) {
		int u = e.first, w = e.second;
		if (u != p) {
			par[0][u] = v;
			for (int i = 1; i < 20; ++i) {
				par[i][u] = par[i - 1][par[i - 1][u]];
			}
			dep[u] = dep[v] + 1;
			dist[u] = (dist[v] + w) % MOD;
			prep(u, v);
		}
	}
	tout[v] = timer;
}

int getpar(int v, int k) {
	for (; k; k -= k & -k) {
		v = par[__builtin_ctz(k)][v];
	}
	return v;
}

int lca(int v, int u) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	u = getpar(u, dep[u] - dep[v]);
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

int calcdist(int v, int u) {
	return ((dist[v] + dist[u]) % MOD - (2ll * dist[lca(u, v)] % MOD) + MOD) % MOD;
}

long long sumdown[N], sumd[N], sum2d[N], ans[N], up2[N], up[N];

void dfs(int v, int p) {
	sz[v] = 1;
	for (auto &e : g[v]) {
		int u = e.first, w = e.second;
		shit[v].push_back(0);
		if (u != p) {
			dfs(u, v);

			sz[v] += sz[u];

			sumd[v] += sumd[u]; sumd[v] %= MOD;
			sumd[v] += 1ll * sz[u] * w % MOD; sumd[v] %= MOD;
			// for each u, dep[u] += w
			
			sum2d[u] = sumd[u] + 1ll * sz[u] * w % MOD; sum2d[u] %= MOD;
			
			shit[v].back() = sumdown[u];
			shit[v].back() += 1ll * w * w % MOD * sz[u] % MOD; shit[v].back() %= MOD;
			shit[v].back() += 2ll * sumd[u] % MOD * w % MOD; shit[v].back() %= MOD;
			// for each u d^2 -> (d + w)^2 = d^2 + 2dw + w^2
			sumdown[v] += shit[v].back(); sumdown[v] %= MOD;
		}
	}
}

void dfs2(int v, int p) {	
	int summ = 0, summm = 0;
	int c = 0;
	for (auto &e : g[v]) {
		if (e.first != p) {
			summm += (sumd[e.first] + 1ll * e.second * sz[e.first] % MOD) % MOD;
			summm %= MOD;
			summ += shit[v][c]; summ %= MOD;
		}
		++c;
	}
	c = 0;
	for (auto &e : g[v]) {
		int u = e.first, w = e.second;
		if (u != p) {
			up2[u] = up2[v];
			// for sum of v and higher
			up2[u] += 2ll * up[v] % MOD * w % MOD; up2[u] %= MOD;
			up2[u] += 1ll * w * w % MOD * (n - sz[v] + 1) % MOD; up2[u] %= MOD;
			//cerr << u + 1 << ' ' << up2[u] << '\n';
			// for the brothers of u
			
			up2[u] += (summ - shit[v][c] + MOD) % MOD;
			int aux = sumd[u];
			aux += 1ll * sz[u] * w % MOD; aux %= MOD;
			up2[u] += 2ll * ((sumd[v] - aux + MOD) % MOD) % MOD * w % MOD; up2[u] %= MOD;
			up2[u] += 1ll * w * w % MOD * (sz[v] - 1 - sz[u]) % MOD; up2[u] %= MOD;
			//cerr << u + 1 << ' ' << up2[u] << '\n';
			up[u] = (up[v] + 1ll * w * (n - sz[u]) % MOD) % MOD;
			up[u] += (summm - (sumd[u] + 1ll * w * sz[u] % MOD) % MOD + MOD) % MOD;
			up[u] %= MOD;
			//cerr << "KKKKK " << u + 1 << ' ' << up[u] << '\n';

			dfs2(u, v);
		}
		++c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		--v, --u;
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}

	prep(0, -1);
	dfs(0, -1);
	dfs2(0, -1);
	
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		int dd = calcdist(u, v);
		
		if (tin[v] <= tin[u] && tout[u] <= tout[v]) {
			int tmp = (up2[v] + 2ll * dd % MOD * up[v] % MOD) % MOD;
			tmp += (1ll * dd * dd % MOD * (n - sz[v]) % MOD); tmp %= MOD;
			int f = (sumdown[u] + up2[u]) % MOD - tmp + MOD; f %= MOD;

			cout << (f - tmp + MOD) % MOD << '\n';
		} else {
			//cerr << up2[u] << ' ' << sumdown[u] << '\n';
			int tmp = (sumdown[v] + 2ll * dd % MOD * sumd[v] % MOD) % MOD;
			tmp += (1ll * dd * dd % MOD * sz[v]) % MOD; tmp %= MOD;
			tmp <<= 1; tmp %= MOD;

			cout << (tmp - ((sumdown[u] + up2[u]) % MOD) + MOD) % MOD << '\n';
		}
	}
}