#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int N = 1e5 + 10;

int n, m, s, t;
long long dist[2][N];

struct Adj {
	int u, w;
};

vector<Adj> g[2][N];

struct Edge {
	int v, u, w;
};

Edge ee[N];

void dijkstra(int x, int v) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	dist[x][v] = 0;
	pq.push({0, v});
	
	while (!pq.empty()) {
		int v = pq.top().second;
		long long d = pq.top().first;
		pq.pop();

		if (d != dist[x][v]) {
			continue;
		}

		for (auto &u : g[x][v]) {
			if (dist[x][u.u] > d + u.w) {
				dist[x][u.u] = d + u.w;
				pq.push({dist[x][u.u], u.u});
			}
		}
	}
}

struct Adj2 {
	int v, i;
};

vector<Adj2> new_g[N];
bool bridge[N], mark[N], tree[N];
int low[N], tin[N], timer;

void dfs(int v, int p) {
	mark[v] = true;
	low[v] = tin[v] = timer++;

	for (auto &e : new_g[v]) {
		if (e.v == p && tree[e.i]) {
			continue;
		}
		if (mark[e.v]) {
			low[v] = min(low[v], tin[e.v]);
		} else {
			tree[e.i] = true;
			dfs(e.v, v);
			low[v] = min(low[v], low[e.v]);
			if (low[e.v] > tin[v]) {
				bridge[e.i] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> s >> t;
	--s;
	--t;
	
	for (int i = 0; i < m; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		ee[i] = {--v, --u, w};
		g[0][v].push_back({u, w});
		g[1][u].push_back({v, w});
	}
	
	fill_n(&dist[0][0], N * 2, 1e14);

	dijkstra(0, s);
	dijkstra(1, t);
	
	for (int i = 0; i < m; ++i) {
		if (dist[0][ee[i].v] + ee[i].w + dist[1][ee[i].u] == dist[0][t]) {
			new_g[ee[i].v].push_back({ee[i].u, i});
			new_g[ee[i].u].push_back({ee[i].v, i});
		}
	}
	
	dfs(s, -1);
	
	for (int i = 0; i < m; ++i) {
		if (bridge[i]) {
			cout << "YES\n";
		} else {
			if (dist[0][t] - dist[0][ee[i].v] - dist[1][ee[i].u] - 1 > 0) {
				cout << "CAN " << ee[i].w - (dist[0][t] - dist[0][ee[i].v] - dist[1][ee[i].u] - 1) << '\n';
			} else {
				cout << "NO\n";
			}
		}
	}
}

