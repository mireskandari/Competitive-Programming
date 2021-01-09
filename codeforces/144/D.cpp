#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, start;
	cin >> n >> m >> start;
	--start;
	
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		g[--v].push_back({--u, w});
		g[u].push_back({v, w});
	}
	
	using PqType = pair<long long, int>;
	priority_queue<PqType, vector<PqType>, greater<PqType>> pq;
	vector<long long> dist(n, 1e14);
	
	dist[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		int v = pq.top().second;
		long long d = pq.top().first;
		pq.pop();
		if (d > dist[v]) {
			continue;
		}

		for (auto &e : g[v]) {
			if (d + e.second < dist[e.first]) {
				dist[e.first] = d + e.second;
				pq.push({dist[e.first], e.first});
			}
		}
	}

	long long l;
	cin >> l;
	int cnt_v = 0;
	for (int i = 0; i < n; ++i) {
		if (dist[i] == l) {
			cnt_v++;
		}
	}
	int cnt_e = 0;
	for (int i = 0; i < n; ++i) {
		for (auto &e : g[i]) {
			if (i < e.first) {
				continue;
			}
			set<long long> point{l - dist[i], 1ll * e.second - (l - dist[e.first])};
			while (!point.empty() && *point.rbegin() >= e.second) {
				point.erase(prev(point.end()));
			}
			while (!point.empty() && *point.begin() <= 0) {
				point.erase(point.begin());
			}
			cnt_e += len(point);
			for (auto &p : point) {
				if (dist[i] + p < l || dist[e.first] + (e.second - p) < l) {
					--cnt_e;
				}
			}
		}
	}

	cout << cnt_v + cnt_e;
	
	return 0;
}

