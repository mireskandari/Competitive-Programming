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

int n, q, inv_n, sz[N], tin[N], tout[N], timer, tmp[N], par[N];
vector<int> g[N];
vector<pair<int, int>> gg[N];

void prep(int v) {
	sz[v] = 1;
	for (auto &u : g[v]) {
		if (u != par[v]) {
			par[u] = v;
			prep(u);
			sz[v] += sz[u];
		}
	}
}

void dfs(int v) {
	tin[v] = timer++;
	if (v != 0) {
		g[v].erase(find(g[v].begin(), g[v].end(), par[v]));
	}
	sort(g[v].begin(), g[v].end(), [&](int ll, int rr) {
		return sz[ll] < sz[rr];
	});
	for (int i = 0, j = 0; i < (int) g[v].size(); i = j) {
		int u = g[v][i];
		while (j < (int) g[v].size() && sz[g[v][j]] == sz[u]) {
			dfs(g[v][j]);
			++j;
		}
		int x = g[v][j - 1];
		gg[v].push_back({u, x});
	}
	tout[v] = timer;
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
	
	prep(0);
	dfs(0);

	while (q--) {
		int op, v;
		cin >> op >> v;
		--v;
		if (op == 1) {
			int d;
			cin >> d;
			
			update(0, n, mult(d, sz[v]));
			update(tin[v], tout[v], mult(d, sub(0, sz[v])));
			for (auto &p : gg[v]) {
				int f = p.first, l = p.second;
				update(tin[f], tout[l], mult(d, n - sz[f]));
			}
			add(tmp[v], d);
		} else {
			int ans = sum(query(tin[v]), mult(n, tmp[v]));
			cout << mult(inv_n, ans) << '\n';
		}
	}
}