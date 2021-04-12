#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int maxn = 1e5 + 10, maxl = 20, maxk = 10;

int n, m, q;
vector<int> g[maxn];
vector<int> ppl[maxn][maxl];
int par[maxn][maxl], dep[maxn];
int lg[maxn];

void shrink(vector<int> &a) {
	a.resize(min(maxk, len(a)));
}

vector<int> combine(const vector<int> &a, const vector<int> &b) {
	vector<int> ret(len(a) + len(b));
	merge(a.begin(), a.end(), b.begin(), b.end(), ret.begin());
	shrink(ret);
	return ret;
}

void dfs(int v) {
	for (int i = 1; i < maxl; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
		ppl[v][i] = combine(ppl[v][i - 1], ppl[par[v][i - 1]][i - 1]);
	}
	for (auto &u : g[v]) {
		if (u != par[v][0]) {
			dep[u] = dep[v] + 1;
			par[u][0] = v;
			dfs(u);
		}
	}
}

int get_par(int v, int k) {
	for (int i = 0; i < maxl; ++i) {
		if ((k >> i) & 1) {
			v = par[v][i];
		}
	}
	return v;
}

vector<int> get_vals(int v, int k) {
	vector<int> ans;
	for (int i = 0; i < maxl; ++i) {
		if ((k >> i) & 1) {
			ans = combine(ans, ppl[v][i]);
			v = par[v][i];
		}
	}
	return ans;
}

int lca(int v, int u) {
	if (dep[v] > dep[u]) {
		swap(u, v);
	}
	u = get_par(u, dep[u] - dep[v]);
	if (v == u) {
		return v;
	}
	for (int i = maxl - 1; i >= 0; --i) {
		if (par[v][i] != par[u][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

void extend(set<int> &x, vector<int> &y) {
	for (auto &i : y) {
		x.insert(i);
	}
}

int main() {
	lg[1] = 0;
	for (int i = 2; i < maxn; ++i) {
		lg[i] = lg[i / 2] + 1;
	}

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		ppl[--x][0].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		shrink(ppl[i][0]);
	}
	
	dfs(0);
	
	while (q--) {
		int v, u, k;
		scanf("%d%d%d", &v, &u, &k);
		--v, --u;
		
		int w = lca(u, v);
		
		vector<int> ans = get_vals(v, dep[v] - dep[w] + 1);
		ans = combine(ans, get_vals(u, dep[u] - dep[w]));
		
		ans.resize(min(len(ans), k));

		printf("%d ", len(ans));
		for (auto &p : ans) {
			printf("%d ", p + 1);
		}
		printf("\n");
	}
}