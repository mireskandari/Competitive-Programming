#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int N = (int) 1e3 + 1;

int dist[N][N];
vector<int> g[N];

void dfs(int x, int v, int p, int d) {
	dist[x][v] = d;
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(x, u, v, d + 1);
		}
	}
}

int n, m, k;
int a[N][2], b[N][3], who[N];

long long sqr(int a) {
	return 1ll * a * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i][0] >> b[i][1] >> b[i][2];
	}

	for (int i = 1; i <= m; ++i) {
		int where = 0, r = INT_MAX;
		for (int j = 1; j <= m; ++j) {
			if (b[j][0] > b[i][0] && b[j][0] < r && sqr(b[j][1] - b[i][1]) + sqr(b[j][2] - b[i][2]) < sqr(b[j][0])) {
				where = j;
				r = b[j][0];
			}
		}
		g[where].push_back(i);
		g[i].push_back(where);
	}
	
	
	for (int i = 0; i < n; ++i) {
		int where = 0, r = INT_MAX;
		for (int j = 1; j <= m; ++j) {
			if (b[j][0] < r && sqr(b[j][1] - a[i][0]) + sqr(b[j][2] - a[i][1]) < sqr(b[j][0])) {
				where = j;
				r = b[j][0];
			}
		}
		who[i] = where;
	}
	
	for (int i = 0; i <= m; ++i) {
		dfs(i, i, -1, 0);
	}

	while (k--) {
		int x, y;
		cin >> x >> y;
		cout << dist[who[--x]][who[--y]] << '\n';
	}
}

