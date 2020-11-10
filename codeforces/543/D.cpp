#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T& a) { return a.size(); }
using ll = long long;

constexpr int MOD = 1000 * 1000 * 1000 + 7;

int Mult(int a, int b) {
	return 1ll * a * b % MOD;
}
void Ok(int& a) {
	if (a >= MOD)
		a -= MOD;
	if (a < 0) 
		a += MOD;
}
int Norm(int a) {
	Ok(a);
	return a;
}

constexpr int N = 2e5 + 10;

int n;
int dp[N][2]; // up, down
vector<int> g[N];
vector<int> suff[N];
vector<int> pref[N];
int idx[N];

void DfsDown(int v, int p) {
	dp[v][0] = 1;
	pref[v].resize(size(g[v]) + 2, 1);
	suff[v].resize(size(g[v]) + 2, 1);
	for (int i = 0, cnter = 0; i < size(g[v]); ++i) {
		int u = g[v][i];
		if (u == p)
			continue;
		idx[u] = ++cnter;
		DfsDown(u, v);
		pref[v][idx[u]] = Mult(pref[v][idx[u] - 1], Norm(dp[u][0] + 1));
		dp[v][0] = Mult(dp[v][0], Norm(dp[u][0] + 1));
	}
	for (int i = size(g[v]) - 1; i >= 0; --i) {
		int u = g[v][i];
		if (u == p)
			continue;
		suff[v][idx[u]] = Mult(suff[v][idx[u] + 1], Norm(dp[u][0] + 1));
	}
}
void DfsUp(int v, int p) {
	for (auto u : g[v]) {
		if (u == p)
			continue;
		Ok(dp[u][1] = Mult(dp[v][1], Mult(suff[v][idx[u] + 1], pref[v][idx[u] - 1])) + 1);
		DfsUp(u, v);
	}
	dp[v][1] = Mult(dp[v][1], dp[v][0]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int v;
		scanf("%d", &v);
		g[--v].push_back(i);
		g[i].push_back(v);
	}
	DfsDown(0, -1);
	dp[0][1] = 1;
	DfsUp(0, -1);
	for (int i = 0; i < n; ++i)
		printf("%d ", dp[i][1]);
	return 0;
}