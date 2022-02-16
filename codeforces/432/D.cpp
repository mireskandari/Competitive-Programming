#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

vector<vector<int>> g;
vector<int> sz;

void dfs(int v) {
	sz[v] = 1;
	for (auto &u : g[v]) {
		dfs(u);
		sz[v] += sz[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	int n = (int) s.size();

	vector<int> f(n);
	int k = 0;
	for (int i = 1; i < n; ++i) {
		while (k && s[i] != s[k]) {
			k = f[k - 1];
		}
		k += (s[i] == s[k]);
		f[i] = k;
	}

	g.resize(n + 1);
	sz.resize(n + 1);
	for (int i = 0; i < n; ++i) {
		g[f[i]].push_back(i + 1);
	}

	dfs(0);

	vector<pair<int, int>> ans;
	ans.push_back({n, 1});
	int i = f[n - 1];
	while (i > 0) {
		ans.push_back({i, sz[i]});
		i = f[i - 1];
	}
	reverse(ans.begin(), ans.end());
	

	cout << ans.size() << '\n';
	for (auto &x : ans) {
		cout << x.first << ' ' << x.second << '\n';
	}
}