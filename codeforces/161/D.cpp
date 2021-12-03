#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 5e4 + 10;

int n, k;
long long ans;
vector<int> g[N];
vector<long long> f[N];

void dfs(int v, int p) {
	f[v].resize(k + 2);
	f[v][1] = 1;
	for (auto &u : g[v]) {
		if (u == p) {
			continue;
		}
		
		dfs(u, v);

		vector<long long> new_dp = f[v];
		for (int i = 1; i <= k; ++i) {
			ans += f[v][i] * f[u][k + 1 - i];
		}
		for (int i = 1; i < k + 1; ++i) {
			new_dp[i + 1] += f[u][i];
		}
		swap(new_dp, f[v]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}

	dfs(0, -1);

	cout << ans;
}