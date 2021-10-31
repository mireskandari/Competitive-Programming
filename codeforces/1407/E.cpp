#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	vector<set<pair<int, int>>> st(n);
	for (int i = 0; i < m; ++i) {
		int v, u, x;
		cin >> v >> u >> x;
		--v, --u;
		if (st[u].count({v, 2})) {
			continue;
		}
		if (st[u].count({v, !x})) {
			st[u].erase({v, !x});
			st[u].insert({v, 2});
		} else {
			st[u].insert({v, x});
		}
	}
	
	vector<int> x(n, -1);
	vector<int> dist(n, INF);
	dist[n - 1] = 0;
	x[n - 1] = 0;

	queue<int> q;
	q.push(n - 1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		for (auto &p : st[v]) {
			if (dist[p.first] < INF) {
				continue;
			}
			if (p.second != 2) {
				if (~x[p.first] && (!p.second) != x[p.first]) {
					dist[p.first] = dist[v] + 1;
					q.push(p.first);
				} else {
					x[p.first] = !p.second;
				}
			} else {
				if (x[p.first] == -1) {
					x[p.first] = 0;
				}
				dist[p.first] = dist[v] + 1;
				q.push(p.first);
			}
		}
	}

	cout << (dist[0] >= INF ? -1 : dist[0]) << '\n';
	for (int i = 0; i < n; ++i) {
		cout << (x[i] < 0 ? 0 : x[i]);
	}
}