#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 2e5 + 10;

int k;
long long mn, mx;
vector<pair<int, int>> g[N];

int dfs(int v, int p) {
	int sz = 1;
	for (auto &e : g[v]) {
		if (e.first != p) {
			int ret = dfs(e.first, v);
			mx += 1ll * e.second * min(ret, 2 * k - ret);
			mn += 1ll * e.second * (ret & 1);
			sz += ret;
		}
	}
	
	return sz;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	
	while (tc--) {
		mn = mx = 0;
		cin >> k;
		fill(g, g + 2 * k, vector<pair<int, int>>());
		for (int i = 0; i < 2 * k - 1; ++i) {
			int v, u, w;
			cin >> v >> u >> w;
			g[--v].push_back({--u, w});
			g[u].push_back({v, w});
		}
		dfs(0, -1);
		cout << mn << ' ' << mx << '\n';
	}
}