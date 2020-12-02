#include <bits/stdc++.h>
using namespace std;
template <typename T> int len(const T& a) { return a.size(); }

constexpr int mxn = 6e5 + 10;

int shit[mxn];

int root(int v) {
	return shit[v] < 0 ? v : (shit[v] = root(shit[v]));
}

void unite(int v, int u) {
	v = root(v), u = root(u);
	if (v == u) {
		return;
	}
	if (shit[u] < shit[v]) {
		swap(u, v);
	}
	shit[v] += shit[u];
	shit[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(shit, -1, sizeof(shit));
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> deg(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u);
		g[u].push_back(v);
		deg[v]++;
		deg[u]++;
		unite(u, v);
	}
	int negat = 0;
	for (int i = 0; i < n; ++i) {
		if (root(i) < 0) {
			++negat;
		}
	}
	if (negat > 1) {
		cout << 1 << '\n' << n << ' ';
		for (int i = 1; i <= n; ++i) {
			cout << i << ' ';
		}
		exit(0);
	}
	for (int i = 0; i < n; ++i) {
		sort(g[i].begin(), g[i].end());
	}
	memset(shit, -1, sizeof(shit));
	int mndeg = min_element(deg.begin(), deg.end()) - deg.begin();
	vector<int> fcompo{mndeg}, scompo;
	for (int i = 0; i < n; ++i) {
		if (!binary_search(g[mndeg].begin(), g[mndeg].end(), i)) {
			if (i != mndeg) {
				fcompo.push_back(i);
				unite(i, mndeg);
			}
		} else {
			scompo.push_back(i);
		}
	}
	for (auto v : scompo) {
		for (auto u : scompo) {
			if (!binary_search(g[v].begin(), g[v].end(), u)) {
				if (v != u) {
					unite(u, v);
				}
			} else {
				deg[v]--;
			}
		}
	}
	for (auto v : scompo) {
		if (deg[v] != len(fcompo)) {
			unite(mndeg, v);
		}
	}
	vector<vector<int>> parts(n);
	for (int i = 0; i < n; ++i) {
		parts[root(i)].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!parts[i].empty()) {
			++ans;
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		if (!parts[i].empty()) {
			cout << len(parts[i]) << ' ';
			for (auto v : parts[i]) {
				cout << v + 1 << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}

