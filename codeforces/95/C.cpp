#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s, --t;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		g[--v].push_back({--u, w});
		g[u].push_back({v, w});
	}
	vector<pair<int, int>> taxi(n);
	for (int i = 0; i < n; ++i) {
		cin >> taxi[i].first >> taxi[i].second;
	}
	vector<vector<long long>> dist(n, vector<long long>(n, 1e13));
	for (int i = 0; i < n; ++i) {
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		pq.push({0, i});
		dist[i][i] = 0;
		while (!pq.empty()) {
			int v = pq.top().second;
			long long d = pq.top().first;
			pq.pop();
			if (d > dist[i][v]) {
				continue;
			}
			for (auto &e : g[v]) {
				int u = e.first, w = e.second;
				if (d + w < dist[i][u]) {
					dist[i][u] = d + w;
					pq.push({dist[i][u], u});
				}
			}
		}
	}
	vector<long long> dist2(n, 1e13);
	vector<bool> mark(n);
	dist2[s] = 0;
	for (int z = 0; z < n; ++z) {
		int v = -1;
		long long d = LLONG_MAX;
		for (int u = 0; u < n; ++u) {
			if (!mark[u] && dist2[u] < d) {
				d = dist2[u];
				v = u;
			}
		}
		mark[v] = true;
		for (int u = 0; u < n; ++u) {
			if (dist[v][u] <= taxi[v].first && dist2[u] > dist2[v] + taxi[v].second) {
				dist2[u] = dist2[v] + taxi[v].second;
			}
		}
	}
	cout << (dist2[t] < (long long) 1e13 ? dist2[t] : -1ll);
	return 0;
}

