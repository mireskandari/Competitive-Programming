#include <bits/stdc++.h>
using namespace std;
template <typename T> int len(const T& a) { return a.size(); }

void setmin(int& a, int b) {
	a = min(a, b);
}

constexpr int mxn = 5e3 + 10, inf = 0x3f3f3f3f;
constexpr array<int, 2> infarr = {inf, inf};

int n, leaf[mxn];
vector<array<int, 2>> dp[mxn]; // number of blues, blue or not (1, 0)
vector<int> g[mxn];

void dfs1(int v, int p) {
	leaf[v] = len(g[v]) == 1 ? 1 : 0;
	for (auto u : g[v]) {
		if (u == p) {
			continue;
		}
		dfs1(u, v);
		leaf[v] += leaf[u];
	}
}

void dfs(int v, int p) {
	int until = 0;
	dp[v] = vector<array<int, 2>>(leaf[v] + 1, infarr);
	dp[v][0][0] = 0;
	if (len(g[v]) == 1) {
		dp[v][1][1] = 0;
	} else {
		dp[v][0][1] = 0;
	}
	for (auto u : g[v]) {
		if (u == p) {
			continue;
		}
		dfs(u, v);
		vector<array<int, 2>> new_dp(leaf[v] + 1, infarr);
		for (int i = 0; i <= until; ++i) {
			for (int j = 0; j <= leaf[u]; ++j) {
				for (int x = 0; x < 2; ++x) {
					for (int y = 0; y < 2; ++y) {
						if (i + j >= len(new_dp)) {
							continue;
						}
						setmin(new_dp[i + j][x], dp[v][i][x] + dp[u][j][y] + (x != y));
					}
				}
			}
		}
		dp[v].swap(new_dp);
		until += leaf[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	int root = 0;
	while (len(g[root]) == 1) {
		++root;
	}
	dfs1(root, -1);
	dfs(root, -1);
	/*for (int v = 0; v < n; ++v) {
		cerr << v << endl;
		for (int j = 0; j <= leaf[v]; ++j) {
			cerr << dp[v][j][0] << ' ' << dp[v][j][1] << endl;
		}
	}*/
	cout << min(dp[root][leaf[root] / 2][0], dp[root][leaf[root] / 2][1]);
	return 0;
}

