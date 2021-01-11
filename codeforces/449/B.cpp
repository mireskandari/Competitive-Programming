#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		g[--v].push_back({--u, w});
		g[u].push_back({v, w});
	}
	for (int i = 0; i < k; ++i) {
		int u, w;
		cin >> u >> w;
		g[0].push_back({--u, -w});
		g[u].push_back({0, -w});
	}

	using PqT = pair<long long, int>;
	priority_queue<PqT, vector<PqT>, greater<PqT>> pq;
	vector<long long> dist(n, 1e13);

	dist[0] = 0;
	pq.push({dist[0], 0});

	while (!pq.empty()) {
		int v = pq.top().second;
		long long d = pq.top().first;
		pq.pop();
		if (d > dist[v]) {
			continue;
		}

		for (auto &e : g[v]) {
			int u = e.first, w = abs(e.second);
			if (d + w < dist[u]) {
				dist[u] = d + w;
				pq.push({dist[u], u});
			}
		}
	}
	
	int edges = 0;
	vector<int> indeg(n);
	for (int v = 0; v < n; ++v) {
		for (auto &e : g[v]) {
			if (dist[v] + abs(e.second) == dist[e.first]) {
				indeg[e.first]++;
				if (e.second < 0) {
					++edges;
				}
			}
		}
	}
	
	for (auto &e : g[0]) {
		if (e.second < 0 && abs(e.second) == dist[e.first] && indeg[e.first] > 1) {
			edges--;
			indeg[e.first]--;
		}
	}

	cout << k - edges;
	
	return 0;
}
