#include <bits/stdc++.h>
using namespace std;
#define bg(a) cerr << "    " << #a << ":" << a
template <typename T> inline int len(const T &a) { return a.size(); }

struct dsu {
	vector<int> dat;

	dsu(int n) : dat(n, -1) {}

	int root(int v) {
		return dat[v] < 0 ? v : (dat[v] = root(dat[v]));
	}

	void unite(int v, int u) {
		v = root(v), u = root(u);
		if (v == u) {
			return;
		}
		if (dat[u] < dat[v]) {
			swap(v, u);
		}
		dat[v] += dat[u];
		dat[u] = v;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> edges(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		edges[i] = {w, --v, --u, i};
	}
	
	vector<long long> ans(n - 1);
	sort(edges.begin(), edges.end());
	dsu ds(n);
	for (int i = 0, j = 0; i < n - 1; i = j) {
		while (j < n - 1 && get<0>(edges[j]) == get<0>(edges[i])) {
			++j;
		}
		if (i == j) {
			continue;
		}
		
		vector<int> roots;
		for (int k = i; k < j; ++k) {
			roots.push_back(ds.root(get<1>(edges[k])));
			roots.push_back(ds.root(get<2>(edges[k])));
		}
		sort(roots.begin(), roots.end());
		roots.resize(unique(roots.begin(), roots.end()) - roots.begin());
		
		auto idx = [&](int val) {
			return lower_bound(roots.begin(), roots.end(), val) - roots.begin();
		};
		
		int rootsn = len(roots);
		
		vector<vector<int>> g(rootsn);
		for (int k = i; k < j; ++k) {
			int v = idx(ds.root(get<1>(edges[k]))), u = idx(ds.root(get<2>(edges[k])));
			g[v].push_back(u);
			g[u].push_back(v);
		}
		
		vector<int> sizes(rootsn);
		for (int k = 0; k < rootsn; ++k) {
			sizes[k] = -ds.dat[roots[k]];
		}
		
		vector<int> sz(rootsn), compsz(rootsn);
		vector<vector<int>> comp;
		vector<bool> mark(rootsn);
		function<void(int)> dfs = [&](int v) {
			sz[v] = sizes[v];
			mark[v] = true;
			comp.back().push_back(v);
			for (auto &u : g[v]) {
				if (!mark[u]) {
					dfs(u);
					sz[v] += sz[u];
				}
			}
		};
		for (int k = 0; k < rootsn; ++k) {
			if (!mark[k]) {
				comp.push_back({});
				dfs(k);
				for (auto &v : comp.back()) {
					compsz[v] = sz[k];
				}
			}
		}

		for (int k = i; k < j; ++k) {	
			int v = idx(ds.root(get<1>(edges[k]))), u = idx(ds.root(get<2>(edges[k])));
			if (sz[v] < sz[u]) {
				swap(v, u);
			}
			ans[get<3>(edges[k])] = 2ll * sz[u] * (compsz[u] - sz[u]);
		}

		for (int k = i; k < j; ++k) {
			ds.unite(get<1>(edges[k]), get<2>(edges[k]));
		}
	}
	
	auto mx = *max_element(ans.begin(), ans.end());
	vector<int> good;
	for (int i = 0; i < n - 1; ++i) {
		if (ans[i] == mx) {
			good.push_back(i + 1);
		}
	}
	cout << mx << ' ' << len(good) << '\n';
	for (auto &e : good) {
		cout << e << ' ';
	}
	return 0;
}

