#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n;
vector<int> g[N];
vector<int> chips;
int dist[N];

void bfs() {
	memset(dist, 0x3f, sizeof(dist));
	queue<int> q;
	for (auto &chip : chips) {
		q.push(chip);
		dist[chip] = 0;
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto &u : g[v]) {
			if (dist[u] > dist[v] + 1) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
}

int sz[N], dep[N];
int arr[N][2];
int ans[N], best[N];
vector<pair<int, pair<int, int>>> a;
bool used[N];

void dfs(int v, int p, int r) {
	sz[v] = 1;
	
	a.push_back({dep[v], {-v, r}});
	int x = dist[v] - dep[v] - 1;
	if (x >= 0) {
		a.push_back({x, {r + 1, dist[v]}});
	}
	
	for (auto &u : g[v]) {
		if (u != p && !used[u]) {
			dep[u] = dep[v] + 1;
			dfs(u, v, p == -1 ? u : r);
			sz[v] += sz[u];
		}
	}
}

priority_queue<pair<int, int>> pq;

pair<int, int> getlast() {
	while (!pq.empty() && best[pq.top().second] != pq.top().first) {
		pq.pop();
	}
	if (pq.empty()) {
		return make_pair(-1, -1);
	}
	return pq.top();
}

void solve(int c) {
	dep[c] = 0;
	dfs(c, -1, c);

	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	reverse(a.begin(), a.end());
	
	for (auto &x : a) {
		int y = x.second.first, yy = x.second.second;
		if (y > 0) {
			--y;
			if (best[y] < yy) {
				best[y] = yy;
				pq.push(make_pair(yy, y));
			}
		} else {
			y = -y;
			auto bg = getlast(); // get the first max
			if (bg.second != c && bg.second == yy) {
				auto tmp = bg;
				pq.pop();
				bg = getlast(); // second max
				pq.push(tmp); // push the first back
				ans[y] = max(ans[y], bg.first);
			} else {
				ans[y] = max(ans[y], bg.first);
			}
		}
	}

	for (auto &x : a) {
		if (x.second.first > 0) {
			best[x.second.first - 1] = 0;
		}
	}
	a.clear();
	while (!pq.empty()) {
		pq.pop();
	}
}

int centroid(int v, int p, int m) {
	int ret = 0, cool = 1;
	sz[v] = 1;
	for (auto &u : g[v]) {
		if (u != p && !used[u]) {
			ret ^= ~centroid(u, v, m);
			cool &= sz[u] <= m >> 1;
			sz[v] += sz[u];
		}
	}
	return cool && m - sz[v] <= m >> 1 ? v : ~ret;
}

void decompose(int v, int m) {
	int c = centroid(v, -1, m);
	solve(c);
	used[c] = true;
	for (auto &u : g[c]) {
		if (!used[u]) {
			decompose(u, sz[u]);
		}
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

	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		chips.push_back(--x);
	}
	
	bfs();
	decompose(0, n);

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
}