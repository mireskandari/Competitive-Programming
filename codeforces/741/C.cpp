#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<vector<int>> g(n << 1);
	vector<pair<int, int>> in(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
		in[i] = {a, b};
	}
	for (int i = 0; i < n; ++i) {
		g[2 * i].push_back(2 * i + 1);
		g[2 * i + 1].push_back(2 * i);
	}
	
	vector<int> mark(n << 1);
	function<void(int, int)> dfs = [&](int v, int c) {
		mark[v] = c;
		for (auto &u : g[v]) {
			if (!mark[u]) {
				dfs(u, 3 - c);
			}
		}
	};
	
	for (int i = 0; i < 2 * n; ++i) {
		if (!mark[i]) {
			dfs(i, 1);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << mark[in[i].first] << ' ' << mark[in[i].second] << '\n';
	}
}