#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
#define int long long

constexpr int N = 1e6 + 10;

int n, dp[N];
long long maxt;
int maxc[N];
int fen1[N];
long long fen2[N];
int cntc[N];
int t[N];

vector<pair<int, int>> g[N];

struct Node {
	int a, b;
};

Node tree[N << 2];

void update(int c, int b, int e, int i, int x, int y) {
	if (i < b || i >= e) {
		return;
	}
	if (e - b == 1) {
		tree[c].a += x;
		tree[c].b += y;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	update(l, b, m, i, x, y);
	update(r, m, e, i, x, y);
	tree[c].a = tree[l].a + tree[r].a;
	tree[c].b = tree[l].b + tree[r].b;
}

int bs(int c, int b, int e, int x) {
	if (e - b == 1) {
		return min(x / b, tree[c].b);
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (tree[l].a <= x) {
		return tree[l].b + bs(r, m, e, x - tree[l].a);
	}
	return bs(l, b, m, x);
}

void dfs(int v, int p, long long remain) {
	update(1, 1, N, t[v], 1ll * cntc[v] * t[v], cntc[v]);
	maxc[v] = bs(1, 1, N, remain);
	int max1 = INT_MIN, max2 = INT_MIN;
	bool ch = false;
	for (auto &e : g[v]) {
		int u = e.first;
		ch = true;
		dfs(u, v, remain - 2ll * e.second);
		if (dp[u] > max1) {
			max2 = max1;
			max1 = dp[u];
		} else if (dp[u] > max2) {
			max2 = dp[u];
		}
	}
	update(1, 1, N, t[v], -1ll * cntc[v] * t[v], -cntc[v]);
	if (v == 0) {
		dp[v] = max(maxc[v], max1);
	} else if (!ch) {
		dp[v] = maxc[v];
	} else {
		dp[v] = max(maxc[v], max2);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> maxt;
	for (int i = 0; i < n; ++i) {
		cin >> cntc[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	for (int i = 1; i < n; ++i) {
		int par, w;
		cin >> par >> w;
		--par;
		g[par].push_back({i, w});
	}
	
	dfs(0, -1, maxt);

	cout << dp[0];
}