#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n);
		for (int i = 0; i < m; ++i) {
			int v, u;
			cin >> v >> u;
			g[--v].push_back(--u);
			g[u].push_back(v);
		}
		vector<int> q, dist(n, -1);
		q.reserve(n);
		q.push_back(0);
		dist[0] = 0;
		for (int x = 0; x < len(q); ++x) {
			int v = q[x];
			for (auto &u : g[v]) {
				if (dist[u] == -1) {
					q.push_back(u);
					dist[u] = dist[v] + 1;
				}
			}
		}
		if (count(dist.begin(), dist.end(), -1)) {
			cout << "NO\n";
			continue;
		}
		vector<int> idx(n);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&](int lhs, int rhs) {
			return dist[lhs] < dist[rhs];
		});
		vector<int> home;
		vector<bool> mark(n);
		for (auto &v : idx) {
			if (mark[v]) {
				continue;
			}
			home.push_back(v);
			for (auto &u : g[v]) {
				if (!mark[u]) {
					mark[u] = true;
				}
			}
		}
		cout << "YES\n" << len(home) << '\n';
		for (auto &v : home) {
			cout << v + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}

