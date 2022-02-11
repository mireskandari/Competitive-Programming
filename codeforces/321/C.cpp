#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int n, sz[N];
vector<int> g[N];
bool used[N];

void prep(int v, int p) {
	sz[v] = 1;
	for (auto &u : g[v]) {
		if (u != p && !used[u]) {
			prep(u, v);
			sz[v] += sz[u];
		}
	}
}

int centroid(int v, int p, int m) {
	bool is = true;
	for (auto &u : g[v]) {
		if (u != p && !used[u]) {
			int ret = centroid(u, v, m);
			if (~ret) {
				return ret;
			}
			if (sz[u] > m / 2) {
				is = false;
			}
		}
	}
	if (m - sz[v] > m / 2) {
		is = false;
	}
	if (is) {
		return v;
	}
	return -1;
}

char color[N];

void solve() {
	queue<pair<int, int>> q;
	q.push({0, 0});
	while (!q.empty()) {
		int v = q.front().first;
		int d = q.front().second;
		q.pop();
		prep(v, -1);
		int c = centroid(v, -1, sz[v]);
		color[c] = d;
		for (auto &u : g[c]) {
			if (!used[u]) {
				q.push({u, d + 1});
			}
		}
		used[c] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	solve();

	for (int i = 0; i < n; ++i) {
		cout << (char) (color[i] + 'A') << ' ';
	}
}