#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 3e5 + 10, SQ = 400;

bool xy[N], pr[N];
int n, q, f[N], cnt[2][N], dep[N], par[N][20], tin[N], tout[N], timer;
vector<int> g[N], order;

void compress() {
	vector<int> xx;
	for (int i = 0; i < n; ++i) {
		xx.push_back(f[i]);
	}
	sort(xx.begin(), xx.end());
	xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
	for (int i = 0; i < n; ++i) {
		f[i] = lower_bound(xx.begin(), xx.end(), f[i]) - xx.begin();
	}
}

void dfs(int v, int p) {
	order.push_back(v);
	tin[v] = timer++;
	for (auto &u : g[v]) {
		if (u != p) {
			dep[u] = dep[v] + 1;
			par[u][0] = v;
			for (int i = 1; i < 20; ++i) {
				par[u][i] = par[par[u][i - 1]][i - 1];
			}
			dfs(u, v);
		}
	}
	order.push_back(v);
	tout[v] = timer++;
}

int get_par(int v, int k) {
	for (int i = 0; i < 20; ++i) {
		if ((k >> i) & 1) {
			v = par[v][i];
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
		return u;
	}
	for (int i = 19; i >= 0; --i) {
		if (par[v][i] != par[u][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

struct Query {
	int l, r, i;
	
	Query() {}

	Query(int l, int r, int i) : l(l), r(r), i(i) {}
	
	bool operator<(const Query &o) const {
		return r < o.r;
	}
};

int xtra[N];
long long ans[N];
vector<Query> qs[N];

long long mans;

void upd(int i) {
	int v = order[i];
	if (pr[v]) {
		cnt[xy[v]][f[v]]--;
		mans -= cnt[!xy[v]][f[v]];
	} else {
		cnt[xy[v]][f[v]]++;
		mans += cnt[!xy[v]][f[v]];
	}
	pr[v] ^= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(xtra, -1, sizeof(xtra));

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> xy[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> f[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	dfs(0, 0);

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		int l = lca(u, v);
		if (tin[u] > tin[v]) {
			swap(u, v);
		}
		if (l == u) {
			qs[tin[u] / SQ].push_back(Query(tin[u], tin[v] + 1, i));
		} else {
			xtra[i] = l;
			qs[tout[u] / SQ].push_back(Query(tout[u], tin[v] + 1, i));
		}
	}
	
	compress();

	for (int i = 0; i < N; ++i) {
		if (qs[i].empty()) {
			continue;
		}
		for (int i = 0; i < n; ++i) {
			cnt[0][i] = cnt[1][i] = 0;
			pr[i] = 0;
		}
		mans = 0;

		sort(qs[i].begin(), qs[i].end());
		int ll = qs[i][0].l, rr = qs[i][0].l;
		for (auto &qq : qs[i]) {
			for (; rr < qq.r; ++rr) {
				upd(rr);
			}
			for (int j = min(qq.l, ll); j < max(qq.l, ll); ++j) {
				upd(j);
			}
			ll = qq.l;
			ans[qq.i] = mans;
			if (~xtra[qq.i]) {
				int w = xtra[qq.i];
				ans[qq.i] += cnt[!xy[w]][f[w]];
			}
			/*for (int j = qq.l; j < qq.r; j++) {
				cout << order[j] << ' ';
			}
			cout << '\n';
			for (int i = 0; i < 10; ++i) {
				cerr << "GIRLS " << i << ": " << cnt[0][i] << " BOYS " << i << ": " << cnt[1][i] << '\n';
			}
			cerr << ll << ' ' << rr << '\n';*/
		}
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}