#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u); g[u].push_back(v);
	}
	vector<bool> is(n);
	int root = -1;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		is[--x] = true;
		root = x;
	}
	
	// determining the subtree which the answer should be in
	vector<int> cnt(n);
	vector<bool> rule(n);

	function<void(int, int)> Dfs = [&](int v, int p) {
		cnt[v] = is[v];
		for (auto u : g[v]) {
			if (u == p) continue;
			Dfs(u, v);
			cnt[v] += cnt[u];
		}
	};
	function<void(int, int, bool)> Make = [&](int v, int p, bool in) {
		rule[v] = in;
		for (auto u : g[v]) {
			if (u == p) continue;
			if (cnt[u] > 0) Make(u, v, true);
			else Make(u, v, false);
		}
	};
	Dfs(root, -1);
	Make(root, -1, true);
	
	int treesize = count(rule.begin(), rule.end(), true);
	vector<int> dist(n);

	function<void(int, int)> GetDist = [&](int v, int p) {
		for (auto u : g[v]) {
			if (!rule[u] || u == p) continue;
			dist[u] = dist[v] + 1;
			GetDist(u, v);
		}
	};
	auto Dist = [&](int v) {
		fill_n(dist.begin(), n, -1);
		dist[v] = 0;
		GetDist(v, -1);
	};
	
	vector<int> cand;
	Dist(root);
	int mx = *max_element(dist.begin(), dist.end());
	for (int i = 0; i < n; ++i) if (is[i] && dist[i] == mx) cand.push_back(i);
	Dist(cand.back());
	mx = *max_element(dist.begin(), dist.end());
	for (int i = 0; i < n; ++i) if (is[i] && dist[i] == mx) cand.push_back(i);
	
	cout << *min_element(cand.begin(), cand.end()) + 1 << '\n';
	cout << (treesize - 1) * 2 - *max_element(dist.begin(), dist.end());
	return 0;
}

