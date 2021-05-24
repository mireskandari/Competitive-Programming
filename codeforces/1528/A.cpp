#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int N = 1e5 + 10;

int n;
int l[N], r[N];
vector<int> g[N];
long long dp[N][2];

void dfs(int v, int p) {
	dp[v][0] = dp[v][1] = 0;
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(u, v);
			dp[v][0] += max(dp[u][1] + abs(l[v] - r[u]), dp[u][0] + abs(l[v] - l[u]));
			dp[v][1] += max(dp[u][1] + abs(r[v] - r[u]), dp[u][0] + abs(r[v] - l[u]));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fill_n(g, n, vector<int>());
		
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> r[i];
		}
		for (int i = 0; i < n - 1; ++i) {
			int v, u;
			cin >> v >> u;
			g[--v].push_back(--u);
			g[u].push_back(v);
		}

		dfs(0, -1);
		
		cout << max(dp[0][1], dp[0][0]) << '\n';
	}
}

