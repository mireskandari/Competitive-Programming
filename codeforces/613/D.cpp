#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int N = 1e5 + 10, LG = 20;

vector<int> g[N];
int par[LG][N], dep[N], tin[N], tout[N];

void dfs(int v, int p) {
	static int timer;

	tin[v] = timer++;

	par[0][v] = p;
	for (int i = 1; i < 20; ++i) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}
	for (auto &u : g[v]) {
		if (u != p) {
			dep[u] = dep[v] + 1;
			dfs(u, v);
		}
	}

	tout[v] = timer++;
}

vector<int> g2[N];
bool is_q[N], is_mid[N];
int par2[N];

array<int, 2> dfs2(int v) { // returns <number of removed vertices, number of not removed queries>	
	array<int, 2> ret = {0, is_q[v]};

	for (auto &u : g2[v]) {
		if (u == par2[v]) {
			continue;
		}
		
		auto got = dfs2(u);
		ret[0] += got[0];
		if (is_q[v] && got[1] > 0) {
			ret[0]++;
		} else {
			ret[1] += got[1];
		}
	}

	if (!is_q[v] && ret[1] > 1) {
		ret = {ret[0] + 1, 0};
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	
	dfs(0, 0);
	
	auto get_par = [&](int v, int k) {
		for (int i = 0; i < 20; ++i) {
			if (k >> i & 1) {
				v = par[i][v];
			}
		}
		return v;
	};

	auto is_par = [&](int p, int v) {
		return tin[p] < tin[v] && tout[v] < tout[p];
	};

	auto lca = [&](int v, int u) {
		if (dep[v] > dep[u]) {
			swap(u, v);
		}
		u = get_par(u, dep[u] - dep[v]);
		if (u == v) {
			return v;
		}
		for (int i = 19; i >= 0; --i) {
			if (par[i][v] != par[i][u]) {
				v = par[i][v];
				u = par[i][u];
			}
		}
		return par[0][v];
	};
	
	int q;
	cin >> q;
	while (q--) {
		//cerr << "KIR\n";
		[&]() {
			int k;
			cin >> k;

			vector<int> a(k);
			set<int> temp; // for keeping real queries
			
			for (int i = 0; i < k; ++i) {
				cin >> a[i];
				--a[i];
				temp.insert(a[i]);
			}
			
			for (int i = 0; i < k; ++i) {
				if (par[0][a[i]] != a[i] && temp.count(par[0][a[i]])) {
					cout << -1 << '\n';
					return;
				}
			}

			sort(a.begin(), a.end(), [&](int lhs, int rhs) {
				return tin[lhs] < tin[rhs];
			});
			
			set<int> used(a.begin(), a.end());

			for (int i = 0; i < k - 1; ++i) {
				int v = a[i], u = a[i + 1];
				if (dep[v] > dep[u]) {
					swap(u, v);
				}

				int w = lca(v, u);
				if (w == v) {
					continue;
				}

				if (!used.count(w)) {
					a.push_back(w);
					used.insert(w);
				}
			}
			
			k = len(a);
			sort(a.begin(), a.end(), [&](int lhs, int rhs) {
				return tin[lhs] < tin[rhs];
			});
			
			memset(is_q, 0, sizeof(bool) * k);
			for (int i = 0; i < k; ++i) {
				is_q[i] = temp.count(a[i]);
			}

			fill_n(g2, k, vector<int>());
			memset(par2, -1, sizeof(int) * k);

			vector<int> stk;
			for (int i = 0; i < k; ++i) {
				while (!stk.empty() && !is_par(a[stk.back()], a[i])) {
					stk.pop_back();
				}
				if (!stk.empty()) {
					par2[i] = stk.back();
					g2[i].push_back(par2[i]);
					g2[par2[i]].push_back(i);
				}
				stk.push_back(i);
				//cerr << "EDGE BETWEEN : " << a[i] + 1 << ' ' << par2[i] + 1 << '\n';
			}
			
			/*cerr << "VERTICES ARE: \n";
			for (auto &v : a) {
				cerr << v + 1 << ' ';
			}
			cerr << '\n';*/
			cout << dfs2(0)[0] << '\n';
		}();
	}
}