#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int n, m;
vector<pair<int, int>> g[N];
bool marke[N];

int dfs(int v) {
	vector<pair<int, int>> nw;
	for (auto &e : g[v]) {
		if (marke[e.second]) {
			continue;
		}
		marke[e.second] = true;
		nw.push_back(e);
	}
	vector<int> vec;
	for (auto &e : nw) {
		int u = e.first;
		int ret = dfs(u);
		if (~ret) {
			cout << ret + 1 << ' ' << u + 1 << ' ' << v + 1 << '\n';
		} else {
			vec.push_back(u);
		}
	}
	while ((int) vec.size() > 1) {
		int s = vec.back();
		vec.pop_back();
		int t = vec.back();
		vec.pop_back();
		cout << s + 1 << ' ' << v + 1 << ' ' << t + 1 << '\n';
	}
	if (vec.empty()) {
		return -1;
	}
	return vec.back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back({u, i});
		g[u].push_back({v, i});
	}
	
	if (m & 1) {
		cout << "No solution";
		exit(0);
	}

	dfs(0);
}	