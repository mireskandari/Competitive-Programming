#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

constexpr int mxn = 5e5 + 10, inf = 0x3f3f3f3f;

int n, m, k, s, t, dist[mxn], hub[mxn], boss[mxn], fromt[mxn];
bool used[mxn];
pair<int, int> edge[mxn];
vector<int> g[mxn];

void prep() {
	memset(dist, 0x3f, sizeof(dist));
	memset(fromt, 0x3f, sizeof(fromt));
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &hub[i]);
		--hub[i];
	}
	for (int i = 0; i < m; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		edge[i] = {--v, --u};
		g[v].push_back(i);
		g[u].push_back(i);
	}
	scanf("%d%d", &s, &t);
	--s;
	--t;
	queue<int> q;
	for (int i = 0; i < k; ++i) {
		q.push(hub[i]);
		dist[hub[i]] = 0;
		boss[hub[i]] = hub[i];
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto e : g[v]) {
			int _, u;
			tie(_, u) = edge[e];
			if (u == v) {
				swap(_, u);
			}
			if (dist[u] >= inf) {
				dist[u] = dist[v] + 1;
				used[e] = true;
				boss[u] = boss[v];
				q.push(u);
			}
		}
	}
	q = queue<int>();
	q.push(t);
	fromt[t] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto e : g[v]) {
			int _, u;
			tie(_, u) = edge[e];
			if (u == v) {
				swap(_, u);
			}
			if (fromt[u] >= inf) {
				fromt[u] = fromt[v] + 1;
				q.push(u);
			}
		}
	}
}

vector<int> gg[mxn];
bool mark[mxn];

void dfs(int v) {
	mark[v] = true;
	for (auto u : gg[v]) {
		if (mark[u]) {
			continue;
		}
		dfs(u);
	}
}

bool check(int q) {
	fill_n(gg, mxn, vector<int>{});
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < m; ++i) {
		if (used[i]) {
			continue;
		}
		int v, u;
		tie(v, u) = edge[i];
		int d = dist[v] + dist[u] + 1;
		if (d <= q) {
			gg[boss[v]].push_back(boss[u]);
			gg[boss[u]].push_back(boss[v]);
		}
	}
	dfs(s);
	for (int i = 0; i < k; ++i) {
		if (mark[hub[i]] && fromt[hub[i]] <= q) {
			return true;
		}
	}
	return false;
}

void run_case() {
	int low = 1, high = n;
	while (high - low > 0) {
		int mid = (low + high) >> 1;
		if (check(mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	if (!check(low)) {
		puts("-1");
	} else {
		printf("%d", low);
	}
}

int main() {
	prep();
	run_case();
	return 0;
}

