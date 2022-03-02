#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}

	int cnt[2] = {};

	function<void(int, int, int)> dfs = [&](int v, int p, int c) {
		cnt[c]++;
		for (auto &u : g[v]) {
			if (u != p) {
				dfs(u, v, !c);
			}
		}
	};
	dfs(0, -1, 0);

	cout << min(cnt[0], cnt[1]) - 1 << '\n';
}