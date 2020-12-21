#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> m;
	
	vector<pair<int, int>> es(m);
	vector<int> deg(7);
	vector<vector<int>> g(7);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		es[i] = {v, u};
		deg[v]++;
		deg[u]++;
		g[v].push_back(i);
		g[u].push_back(i);
	}
	vector<int> odd;
	for (int i = 1; i <= 6; ++i) {
		if (deg[i] & 1) {
			if (len(odd) == 2) {
				cout << "No solution";
				exit(0);
			} else {
				odd.push_back(i);
			}
		}
	}
	
	vector<bool> emark(m);
	vector<pair<int, bool>> tour;

	function<void(int)> dfs = [&](int v) {
		for (int e; !g[v].empty(); ) {
			e = g[v].back();
			g[v].pop_back();
			if (emark[e]) {
				continue;
			}
			emark[e] = true;
			int _, u;
			tie(_, u) = es[e];
			bool swaped = false;
			if (v == u) {
				swaped = true;
				swap(_, u);
			}
			dfs(u);
			tour.push_back({e, !swaped});
		}
	};
	dfs(odd.empty() ? find_if(deg.begin(), deg.end(), [](int x) { return x > 0; }) - deg.begin() : odd.back());
	
	if (len(tour) < m) {
		cout << "No solution";
		exit(0);
	}

	for (auto &p : tour) {
		cout << p.first + 1 << ' ' << (p.second ? '-' : '+') << '\n';
	}
	return 0;
}

