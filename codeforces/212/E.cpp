#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr int N = 5e3 + 10;

int n;
vector<int> g[N];
int sz[N];
bool dp[N][N];

void DfsI(int v, int p) {
	sz[v] = 1;
	for (auto u : g[v]) {
		if (u != p) {
			DfsI(u, v);
			sz[v] += sz[u];
		}
	}
	dp[v][0] = true;
	for (auto u : g[v]) {
		if (u != p) {
			for (int i = sz[v] - 1; i >= 1; --i) {
				if (i - sz[u] >= 0)
					dp[v][i] |= dp[v][i - sz[u]];
			}
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
	DfsI(0, -1);
	set<pair<int, int>> ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < sz[i]; ++j) {
			if (!dp[i][j]) {
				continue;
			}
			auto first = make_pair(j, n - j - 1);
			auto second = make_pair(j + (n - sz[i]), sz[i] - 1 - j);
			if (first.first > 0 && first.second > 0) {
				ans.insert(first);
			}
			if (second.first > 0 && second.second > 0) {
				ans.insert(second);
			}
		}
	}
	cout << len(ans) << '\n';
	for (auto i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
	return 0;
}

