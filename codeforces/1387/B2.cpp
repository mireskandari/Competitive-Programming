#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e6 + 10;

long long ans_num;
vector<int> g[N];
int sz[N];
int n;
vector<int> vec;

int dfs(int v, int p) {
	vec.push_back(v);
	int ret = 0, cool = 1;
	sz[v] = 1;
	for (auto &u : g[v]) {
		if (u != p) {
			ret ^= ~dfs(u, v);
			sz[v] += sz[u];
			cool &= sz[u] <= n / 2;
			ans_num += min(n - sz[u], sz[u]);
		}
	}
	return cool && n - sz[v] <= n / 2 ? v : ~ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	int c = dfs(0, -1);
	vec.clear();
	dfs(c, -1);
	
	cout << ans_num << '\n';
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[vec[i]] = vec[(i + (n + 1) / 2) % n] + 1;
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
}