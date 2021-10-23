#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 3e5 + 10;

int a[N], n;
vector<int> g[N];
long long mx_all;

long long dfs(int v, int p) {
	long long res = a[v];
	for (auto &u : g[v]) {
		if (u != p) {
			auto ret = dfs(u, v);
			if (ret > 0) {
				res += ret;
			}
		}
	}
	mx_all = max(mx_all, res);
	return res;
}

int k;

long long dfss(int v, int p) {
	long long res = a[v];
	for (auto &u : g[v]) {
		if (u != p) {
			auto ret = dfss(u, v);
			if (ret > 0) {
				res += ret;
			}
		}
	}
	if (res == mx_all) {
		++k;
		return 0;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}

	mx_all = LLONG_MIN;
	dfs(0, 0);
	dfss(0, 0);

	cout << 1ll * k * mx_all << ' ' << k;
}