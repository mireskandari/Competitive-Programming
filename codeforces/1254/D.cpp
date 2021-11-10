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

constexpr int N = 15e4 + 10;

int tmp[N], up[N], inv_n, n, q, par[N], bigc[N], sz[N], tin[N], tout[N], timer;
vector<int> g[N];

int dfs(int v) {
	tin[v] = timer++;
	int res = 1, big = -1, bigs = 0;
	for (auto &u : g[v]) {
		if (u != par[v]) {
			par[u] = v;
			int szu = dfs(u);
			res += szu;
			if (szu > bigs) {
				big = u;
				bigs = szu;
			}
		}
	}
	sz[v] = res;
	bigc[v] = big;
	tout[v] = timer;
	return res;
}

void decomp(int v, int l) {
	up[v] = l;
	if (bigc[v] != -1) {
		decomp(bigc[v], l);
	}
	for (auto &u : g[v]) {
		if (u != par[v] && u != bigc[v]) {
			decomp(u, u);
		}
	}
}

int fen[N];

void upd(int i, int x) {
	for (++i; i < N; i += i & -i) {
		add(fen[i], x);
	}
}

void update(int l, int r, int x) {
	upd(l, x);
	upd(r, sub(0, x));
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
	inv_n = inv(n);
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	dfs(0);
	decomp(0, 0);

	while (q--) {
		int op, v;
		cin >> op >> v;
		--v;
		if (op == 1) {
			int d;
			cin >> d;
			
			update(0, n, mult(d, sz[v]));
			update(tin[v], tout[v], mult(d, sub(0, sz[v])));

			if (bigc[v] != -1) {
				update(tin[bigc[v]], tout[bigc[v]], mult(d, n - sz[bigc[v]]));
			}
			add(tmp[v], d);
		} else {
			int ans = sum(query(tin[v]), mult(n, tmp[v]));
			//cerr << "INIT: " << v << ' ' << ans << '\n';
			int u = up[v];
			while (u != 0) {
			//	cerr << v << ' ' << u << '\n';
				add(ans, mult(tmp[par[u]], n - sz[u]));
				u = up[par[u]];

			}
			cout << mult(inv_n, ans) << '\n';
		}
	}
}