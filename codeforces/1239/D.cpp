#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e6 + 10;

int n, m, num[N];
bool mark[N];
vector<int> g[N], ig[N];
vector<int> order;

void dfs(int v) {
	mark[v] = true;
	for (auto &u : g[v]) {
		if (!mark[u]) {
			dfs(u);
		}
	}
	order.push_back(v);
}

void rdfs(int v, int comp) {
	/*if (v % 2 != 0) {
		cout << "CAT: " << v / 2 << '\n';
	} else {
		cout << "MOTHERFUCKER: " << v / 2 << '\n';
	}*/
	num[v] = comp;
	mark[v] = true;
	for (auto &u : ig[v]) {
		if (!mark[u]) {
			rdfs(u, comp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		int sz = 2 * n + 2;
		order.clear();
		for (int i = 0; i < sz; ++i) {
			g[i] = vector<int>();
			ig[i] = vector<int>();
			mark[i] = false;
		}
		for (int i = 0; i < m; ++i) {
			int v, u;
			cin >> v >> u;
			v *= 2;
			u *= 2;
			u++;
			if (u / 2 == v / 2) {
				g[u].push_back(v);
				ig[v].push_back(u);
			} else {
				g[v].push_back(u);
				ig[u].push_back(v);
			}
		}
		for (int i = 2; i < sz; ++i) {
			if (!mark[i]) {
				dfs(i);
			}
		}
		reverse(order.begin(), order.end());
		for (int i = 0; i < sz; ++i) {
			mark[i] = false;
		}
		int comp = 0;
		for (auto &i : order) {
			if (!mark[i]) {
				rdfs(i, ++comp);
			}
		}
		/*for (int i = 2; i < sz; ++i) {
			cout << num[i] << ' ';
		}
		cout << '\n';*/
		if (n == 1 || comp == 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < sz; ++i) {
				mark[i] = false;
			}
			int cnt = 0;
			for (int i = 2; i < sz; ++i) {
				if (!mark[i / 2] && num[i] == comp) {
					cnt++;
					mark[i / 2] = true;
				}
			}
			cout << cnt << ' ' << n - cnt << '\n';
			for (int i = 1; i <= n; ++i) {
				if (mark[i]) {
					cout << i << ' ';
				}
			}
			cout << '\n';
			for (int i = 1; i <= n; ++i) {
				if (!mark[i]) {
					cout << i << ' ';
				}
			}
			cout << '\n';
		}
	}
}