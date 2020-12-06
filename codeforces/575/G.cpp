#pragma GCC optimize("O3")
#pragma GCC target("avx,fma,avx2")
#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

constexpr int mxn = 1e5 + 10, inf = 0x3f3f3f3f;

int dist[mxn], dist2[mxn], cls[mxn], gp_number[mxn];
bool mark[mxn];

struct my_shitty_pair {
	int first, second;
} parent[mxn];
vector<my_shitty_pair> g[mxn];

int main() {
	memset(cls, -1, sizeof(cls));
	memset(gp_number, -1, sizeof(gp_number));
	memset(dist, 0x3f, sizeof(dist));
	memset(dist2, 0x3f, sizeof(dist2));

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}

	queue<int> q;
	vector<int> level;
	q.push(n - 1);
	dist2[n - 1] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		dist[v] = 0;
		cls[v] = 0;
		mark[v] = true;
		level.push_back(v);
		for (auto& e : g[v]) {
			int u = e.first, w = e.second;
			if (w == 0 && dist2[u] >= inf) {
				dist2[u] = dist2[v] + 1;
				parent[u] = {v, 0};
				q.push(u);
			}
		}
	}
	
	vector<int> cnt(n);
	int step = 0;
	while (!level.empty()) {
		assert(step <= n);
		vector<int> nxt_level;
		int cls_it = 0;
		for (int j = 0; j < len(level); ) {
			int c = cls[level[j]];
			int i = j;
			while (i < len(level) && c == cls[level[i]]) {
				int v = level[i];
				++cnt[v];
				assert(cnt[v] == 1);
				for (auto& e : g[v]) {
					int u = e.first, w = e.second;
					assert(u < n);
					if (dist[u] >= inf) {
						dist[u] = dist[v] + 1;
						parent[u] = {v, w};
						gp_number[u] = cls_it;
					} else if (gp_number[u] == cls_it && dist[u] == dist[v] + 1 && parent[u].second > w) {
						parent[u] = {v, w};
					}
				}
				++i;
			}
			assert(i != j);
			for (; j < i; ++j) {
				int v = level[j];
				for (auto& e : g[v]) {
					int u = e.first;
					if (!mark[u] && dist[u] == dist[v] + 1 && gp_number[u] == cls_it) {
						mark[u] = true;
						nxt_level.push_back(u);
						cls[u] = cls_it + parent[u].second;
					}
				}
			}
			cls_it += 10;
		}
		sort(nxt_level.begin(), nxt_level.end(), [&](int lhs, int rhs) {
			return cls[lhs] < cls[rhs];
		});
		swap(level, nxt_level);
		++step;
	}
	
	int x = 0;
	string cost;
	vector<int> path{0};
	step = 0;
	while (x != n - 1) {
		assert(step <= n);
		cost += (char) (parent[x].second + '0');
		path.push_back(parent[x].first);
		x = parent[x].first;
		step++;
	}
	while (!cost.empty() && cost.back() == '0') {
		cost.pop_back();
	}
	
	reverse(cost.begin(), cost.end());
	if (cost.empty()) {
		puts("0");
	} else {
		printf("%s\n", cost.c_str());
	}
	printf("%d\n", len(path));
	for (auto& v : path) {
		printf("%d ", v);
	}
	return 0;
}

