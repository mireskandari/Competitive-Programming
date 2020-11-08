#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T& a) { return a.size(); }
using ll = long long;

const ll MOD = 998244353;
const int N = 3e5 + 10;

ll dp[N][3];
vector<int> g[N];

void Dfs(int v, int p) {
	dp[v][0] = 1;
	dp[v][1] = 1;
	dp[v][2] = 1;
	ll rm = 1;
	for (auto& u : g[v]) {
		if (u == p)
			continue;
		Dfs(u, v);
		dp[v][0] *= (dp[u][1] + dp[u][2] + dp[u][0]) % MOD;
		dp[v][0] %= MOD;
		dp[v][1] *= (3 * dp[u][0] + 2 * dp[u][1] + 2 * dp[u][2]) % MOD;
		dp[v][1] %= MOD;
		dp[v][2] *= (dp[u][2] + 2 * dp[u][1] + 2 * dp[u][0]) % MOD;
		dp[v][2] %= MOD;
		rm *= (dp[u][1] + dp[u][2] + dp[u][0]) % MOD;
		rm %= MOD;
	}
	dp[v][1] -= rm;
	dp[v][2] -= rm;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}

	Dfs(0, -1);
	cout << (dp[0][0] + dp[0][1] + dp[0][2] - 1 + (MOD << 2)) % MOD;

	return 0;
}
/*
dp[v][2] = mult(dp[u][2] + 2*dp[u][1] + 2*dp[u][0]) - mult(dp[u][2] + dp[u][1] + dp[u][0])
dp[v][1] = mult(3*dp[u][0] + 2*dp[u][1] + 2*dp[u][2]) - mult(dp[u][1] + dp[u][2] + dp[u][0])
dp[v][0] = mult(dp[u][0] + dp[u][1] + dp[u][2])
*/
