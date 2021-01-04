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
		vector<vector<int>> g(n), ig(n);
		for (int i = 0; i < m; ++i) {
			int v, u;
			cin >> v >> u;
			g[--v].push_back(--u);
			ig[u].push_back(v);
		}
		constexpr int inf = 0x3f3f3f3f;
		vector<int> dist(n, inf);
		dist[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto &u : g[v]) {
				if (dist[u] >= inf) {
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}
		vector<pair<int, int>> src;
		for (int i = 0; i < n; ++i) {
			int mn = INT_MAX;
			for (auto &u : g[i]) {
				if (dist[u] <= dist[i]) {
					mn = min(mn, dist[u]);
				}
			}
			if (mn < INT_MAX) {
				src.push_back({mn, i});
			}
		}
		sort(src.begin(), src.end());
		vector<bool> mark(n);
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = dist[i];
		}
		function<void(int, int)> dfs = [&](int v, int val) {
			mark[v] = true;
			ans[v] = min(val, ans[v]);
			for (auto &u : ig[v]) {
				if (!mark[u] && dist[u] < dist[v]) {
					dfs(u, val);
				}
			}
		};
		for (auto &v : src) {
			if (!mark[v.second]) {
				dfs(v.second, v.first);
			}
		}
		for (auto &i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}

