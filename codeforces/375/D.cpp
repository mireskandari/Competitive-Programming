#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

vector<int> g[N];
int n, m;
vector<int> st[N];
int cnt[N], sz[N], col[N];
int fen[N + 1];
vector<pair<int, int>> que[N];
int ans[N];

void update(int i, int x) {
	i = N - 1 - i;
	for (++i; i < N + 1; i += i & -i) {
		fen[i] += x;
	}
}

int query(int i) {
	i = N - 1 - i;
	int res = 0;
	for (++i; i > 0; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

void change(int c, int num) {
	update(cnt[c], -1);
	cnt[c] += num;
	update(cnt[c], +1);
}

void prep(int v, int p) {
	sz[v] = 1;
	for (auto &u : g[v]) {
		if (u != p) {
			prep(u, v);
			sz[v] += sz[u];
		}
	}
}

void dfs(int v, int p, bool keep) {
	sz[v] = 1;
	int big = -1, bigs = 0;
	for (auto &u : g[v]) {
		if (u != p) {
			sz[v] += sz[u];
			if (bigs < sz[u]) {
				big = u;
				bigs = sz[u];
			}
		}
	}

	if (~big) {
		for (auto &u : g[v]) {
			if (u != p && u != big) {
				dfs(u, v, false);
			}
		}
		dfs(big, v, true);
		st[v].swap(st[big]);
		for (auto &u : g[v]) {
			if (u != p && u != big) {
				for (auto &color : st[u]) {
					change(color, +1);
					st[v].push_back(color);
				}
			}
		}
	} else {
		st[v] = vector<int>();
	}
	
	st[v].push_back(col[v]);
	change(col[v], +1);

	for (auto &qq : que[v]) {
		ans[qq.second] = query(qq.first);
	}

	if (!keep) {
		for (auto &color : st[v]) {
			change(color, -1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 0; i < N; ++i) {
		update(0, +1);
	}

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> col[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for (int i = 0; i < m; ++i) {
		int v, k;
		cin >> v >> k;
		--v;
		que[v].push_back({k, i});
	}
	
	prep(0, -1);
	dfs(0, -1, true);

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}