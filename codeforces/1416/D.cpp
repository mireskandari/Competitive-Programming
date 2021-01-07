#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int maxn = 1e6 + 10;

int n, m, q, p[maxn];
pair<int, int> edges[maxn], queries[maxn];
bool edge_mark[maxn], useful[maxn];
vector<pair<int, int>> unite_history;
int parent[maxn], sz[maxn];
set<pair<int, int>> numbers[maxn];
vector<int> component[maxn];
bool mark[maxn];

int root(int v) {
	while (parent[v] != -1) {
		v = parent[v];
	}
	return v;
}

bool unite(int v, int u) {
	v = root(v), u = root(u);
	if (v == u) {
		return false;
	}
	if (sz[u] > sz[v]) {
		swap(u, v);
	}
	unite_history.push_back({v, u});

	parent[u] = v;
	sz[v] += sz[u];

	for (auto &value : numbers[u]) {
		numbers[v].insert(value);
	}

	for (auto &x : component[u]) {
		component[v].push_back(x);
	}

	return true;
}

void rollback() {
	int v = unite_history.back().first, u = unite_history.back().second;
	unite_history.pop_back();

	vector<pair<int, int>> to_erase;
	for (auto &value : numbers[u]) {
		if (!mark[value.second]) {
			numbers[v].erase(value);
		} else {
			to_erase.push_back({p[value.second], value.second});
		}
	}
	for (auto &value : to_erase) {
		numbers[u].erase(value);
	}

	component[v].resize(len(component[v]) - len(component[u]));

	parent[u] = -1;
	sz[v] -= sz[u];
}

int query(int v) {
	v = root(v);
	
	if (numbers[v].empty()) {
		return 0;
	}

	auto best_value = *numbers[v].rbegin();
	mark[best_value.second] = true;
	numbers[v].erase(best_value);

	return best_value.first;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}

	// initializing dsu
	for (int i = 0; i < n; ++i) {
		parent[i] = -1;
		sz[i] = 1;
		numbers[i].insert({p[i], i});
		component[i].push_back(i);
	}

	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &edges[i].first, &edges[i].second);
		edges[i].first--;
		edges[i].second--;
	}
	
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &queries[i].first, &queries[i].second);
		--queries[i].second;
		if (queries[i].first == 2) {
			edge_mark[queries[i].second] = true;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		if (!edge_mark[i]) {
			unite(edges[i].first, edges[i].second);
		}
	}

	for (int i = q - 1; i >= 0; --i) {
		if (queries[i].first == 2) {
			int e = queries[i].second;
			if (unite(edges[e].first, edges[e].second)) {
				useful[i] = true;
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		if (queries[i].first == 1) {
			printf("%d\n", query(queries[i].second));
		} else {
			if (useful[i]) {
				rollback();
			}
		}
	}
	return 0;
}

