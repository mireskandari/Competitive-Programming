#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int n;
int c[N], sz[N], cnt[N];
long long ans[N];
map<int, long long> now;
vector<int> st[N];
vector<int> g[N];

void prep(int v, int p) {
	sz[v] = 1;
	for (auto &u : g[v]) {
		if (u != p) {
			prep(u, v);
			sz[v] += sz[u];
		}
	}
}

void change(int c, int x) {
	now[cnt[c]] -= c;
	if (now[cnt[c]] == 0) {
		now.erase(cnt[c]);
	}
	cnt[c] += x;
	now[cnt[c]] += c;
}

void dfs(int v, int p, bool keep) {
	int bg = 0, big = -1;
	for (auto &u : g[v]) {
		if (u != p) {
			if (sz[u] > bg) {
				big = u;
				bg = sz[u];
			}
		}
	}
	if (big == -1) {
		st[v] = vector<int>();
	} else {
		for (auto &u : g[v]) {
			if (u != p && u != big) {
				dfs(u, v, false);
			}
		}
		dfs(big, v, true);
		st[v].swap(st[big]);
		for (auto &u : g[v]) {
			if (u != p && u != big) {
				for (auto &i : st[u]) {
					change(i, +1);
					st[v].push_back(i);
				}
				vector<int>().swap(st[u]);
			}
		}
	}

	st[v].push_back(c[v]);
	change(c[v], +1);
	
	ans[v] = now.rbegin()->second;

	if (!keep) {
		for (auto &i : st[v]) {
			change(i, -1);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	prep(0, -1);
	dfs(0, -1, true);

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
}