#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

struct dsu {
	vector<int> guys;
	vector<set<int>> qs;

	dsu(int n, vector<pair<int, int>> &queries) : guys(n, -1), qs(n) {
		for (int i = 0; i < len(queries); ++i) {
			qs[queries[i].first].insert(i);
			qs[queries[i].second].insert(i);
		}
	}

	int root(int v) {
		return guys[v] < 0 ? v : guys[v] = root(guys[v]);
	}

	void unite(int v, int u, long long w, vector<long long> &ans) {
		v = root(v), u = root(u);
		if (v == u) {
			return;
		}
		if (guys[u] < guys[v]) {
			swap(u, v);
		}
		for (auto &q : qs[u]) {
			int l = len(qs[v]);
			qs[v].insert(q);
			if (l == len(qs[v])) {
				ans[q] = w;
				qs[v].erase(q);
			}
		}
		set<int>().swap(qs[u]);
		guys[v] += guys[u];
		guys[u] = v;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> hub(k);
	vector<bool> isgood(n);
	for (int i = 0; i < k; ++i) {
		cin >> hub[i];
		--hub[i];
		isgood[hub[i]] = true;
	}
	vector<vector<int>> g(n);
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		edges[i] = {--v, --u};
		g[v].push_back(i);
		g[u].push_back(i);
	}

	vector<pair<int, int>> queries(1);
	cin >> queries[0].first >> queries[0].second;
	--queries[0].first, --queries[0].second;
	for (int i = 0; i < len(queries); ++i) {
		if (!isgood[queries[i].second]) {
			hub.push_back(queries[i].second);
			++k;
		}
	}
	for (int i = 0; i < k; ++i) {
		if (queries[0].first == hub[i]) {
			queries[0].first = i;
			break;
		}
	}
	for (int i = 0; i < k; ++i) {
		if (queries[0].second == hub[i]) {
			queries[0].second = i;
			break;
		}
	}

	constexpr int inf = 0x3f3f3f3f;
	vector<int> dad(n, -1), dist(n, inf);
	queue<int> q;
	for (int i = 0; i < len(hub); ++i) {
		dad[hub[i]] = i;
		dist[hub[i]] = 0;
		q.push(hub[i]);
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto &e : g[v]) {
			int _, u;
			tie(_, u) = edges[e];
			if (u == v) {
				swap(u, _);
			}
			if (dist[u] >= inf) {
				dist[u] = dist[v] + 1;
				dad[u] = dad[v];
				q.push(u);
			}
		}
	}
	
	vector<tuple<long long, int, int>> new_edges;
	for (int i = 0; i < m; ++i) {
		int u, v;
		tie(u, v) = edges[i];
		if (dad[v] != dad[u]) {
			new_edges.push_back({1ll * dist[v] + dist[u] + 1, dad[v], dad[u]});
		}
	}
	sort(new_edges.begin(), new_edges.end());
	dsu ds(k, queries);
	
	vector<long long> ans(len(queries), inf);
	for (int i = 0; i < len(new_edges); ++i) {
		int v, u;
		long long w;
		tie(w, v, u) = new_edges[i];
		ds.unite(v, u, w, ans);
	}

	cout << (ans[0] >= inf ? -1 : ans[0]);
	return 0;
}

