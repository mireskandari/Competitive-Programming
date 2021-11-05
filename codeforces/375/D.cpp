#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10, SQ = 400;

int n, m, a[N], c[N], order[N], tin[N], tout[N], timer;
vector<int> g[N];

void dfs(int v, int p) {
	order[timer] = v;
	tin[v] = timer++;
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(u, v);
		}
	}
	tout[v] = timer;
}

struct Query {
	int l, r, t, i;

	bool operator<(const Query &o) const {
		return r < o.r;
	}
};

vector<Query> qs[N];
int ans[N];

int fen[N], cnt[N];

void upd(int i, int x) {
	i = N - i - 2;
	for (++i; i < N; i += i & -i) {
		fen[i] += x;
	}
}

int query(int i) {
	i = N - i - 2;
	int res = 0;
	for (++i; i > 0; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

void update(int i, int x) {
	upd(cnt[i], -1);
	cnt[i] += x;
	upd(cnt[i], 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	dfs(0, -1);

	for (int i = 0; i < m; ++i) {
		int v, k;
		cin >> v >> k;
		--v;
		qs[tin[v] / SQ].push_back({tin[v], tout[v], k, i});
	}
		
	for (int i = 0; i < n; ++i) {
		if (qs[i].empty()) {
			continue;
		}
		sort(qs[i].begin(), qs[i].end());
		memset(fen, 0, sizeof(fen));
		memset(cnt, 0, sizeof(cnt));
		int ml = qs[i][0].l, mr = qs[i][0].l;
		for (; mr < qs[i][0].r; ++mr) {
			update(c[order[mr]], 1);
		}
		ans[qs[i][0].i] = query(qs[i][0].t);
		bool first = true;
		for (auto &q : qs[i]) {
			if (first) {
				first = false;
				continue;
			}
			for (; mr < q.r; ++mr) {
				update(c[order[mr]], 1);
			}
			if (ml < q.l) {
				for (; ml < q.l; ++ml) {
					update(c[order[ml]], -1);
				}
			} else {
				for (; ml > q.l; --ml) {
					update(c[order[ml - 1]], 1);
				}
			}
			ans[q.i] = query(q.t);
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}