#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 998244353;

int sub(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

int mult(int a, int b) {
	return 1ll * a * b % MOD;
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int inv(int a) {
	int res = 1, k = MOD - 2;
	for (; k; k >>= 1, a = mult(a, a)) {
		if (k & 1) {
			res = mult(res, a);
		}
	}
	return res;
}

constexpr int N = 15e4 + 10, SQ = 400;

int n, q, par[N];
vector<int> heavy_dude;
vector<int> g[N];
vector<pair<int, int>> guys[N];

int sz[N], tin[N], tout[N], timer;

void dfs(int v, int p) {
	par[v] = p;
	tin[v] = timer++;
	guys[v].push_back({timer, v});
	sz[v] = 1;
	if ((int) g[v].size() >= SQ) {
		heavy_dude.push_back(v);
	}
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(u, v);
			sz[v] += sz[u];
			guys[v].push_back({timer, u});
		}
	}
	tout[v] = timer;
}

bool issub(int v, int p) {
	return tin[p] <= tin[v] && tout[v] <= tout[p];
}

bool iscool(int v, int u) {
	return issub(v, u) || issub(u, v);
}

int a[N], fen[N];

void update(int i, int x) {
	for (++i; i < N; i += i & -i) {
		add(fen[i], x);
	}
}

void update(int l, int r, int x) {
	update(l, x);
	update(r, sub(0, x));
}

int query(int i) {
	int res = 0;
	for (++i; i > 0; i -= i & -i) {
		add(res, fen[i]);
	}
	return res;
}

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
	
	int inv_n = inv(n);

	dfs(0, -1);
	
	while (q--) {
		int op;
		cin >> op;
		int v;
		cin >> v;
		--v;
		if (op == 1) {
			int d;
			cin >> d;
			add(a[v], d);
			if ((int) g[v].size() < SQ) {
				int x = mult(d, mult(inv_n, sz[v]));
				update(0, n, x);
				update(tin[v], tout[v], sub(0, x));
				for (auto &u : g[v]) {
					if (u != par[v]) {
						update(tin[u], tout[u], mult(d, mult(inv_n, n - sz[u])));
					}
				}
			}
		} else {
			int ans = sum(a[v], query(tin[v]));
			for (auto &u : heavy_dude) {
				if (u == v) {
					continue;
				}
				if (!iscool(u, v) || issub(u, v)) {
					add(ans, mult(a[u], mult(inv_n, sz[u])));
				} else {
					int x = lower_bound(guys[u].begin(), guys[u].end(), make_pair(tout[v], -1))->second;
					add(ans, mult(a[u], mult(inv_n, n - sz[x])));
				}
			}
			cout << ans << '\n';
		}
	}
}