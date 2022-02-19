#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

vector<int> g[N];
bool used[N];
int n;
char a[N];
int sz[N];

int centroid(int v, int p, int m) {
	int ret = -1;
	sz[v] = 1;
	bool cool = true;
	for (auto &u : g[v]) {
		if (!used[u] && u != p) {
			int t = centroid(u, v, m);
			if (~t) {
				ret = t;
			}
			sz[v] += sz[u];
			if (sz[u] > m / 2) {
				cool = false;
			}
		}
	}
	if (m - sz[v] > m / 2) {
		cool = false;
	}
	return cool ? v : ret;
}

long long ans[N];
int cnt[1 << 20];

long long dfs(int v, int p, int val, vector<int> &vec) {
	sz[v] = 1;
	int x = val ^ (1 << (a[v] - 'a'));
	vec.push_back(x);
	
	long long ret = 0;
	ret += cnt[x];
	for (int i = 0; i < 20; ++i) {
		ret += cnt[x ^ (1 << i)];
	}
	
	for (auto &u : g[v]) {
		if (u != p && !used[u]) {
			ret += dfs(u, v, x, vec);
			sz[v] += sz[u];
		}
	}

	ans[v] += ret;
	//cerr << v + 1 << ' ' << ret << '\n';
	return ret;
}

void decomp(int v, int m) {
	int cent = centroid(v, -1, m);
	
	vector<int> all;
	all.push_back(1 << (a[cent] - 'a'));
	cnt[all.back()]++;
	ans[cent]++;
	//cerr << "SHIT " << cent + 1 << ' ' << 1 << '\n';

	sz[cent] = 1;
	
	for (auto &u : g[cent]) {
		if (!used[u]) {
			vector<int> vec;
			long long tmp = dfs(u, cent, 0, vec);
			ans[cent] += tmp;
			//cerr << cent + 1 << ' ' << tmp << '\n';
			
			sz[cent] += sz[u];

			for (auto &x : vec) {
				all.push_back(x ^ (1 << (a[cent] - 'a')));
				cnt[x ^ (1 << (a[cent] - 'a'))]++;
			}
		}
	}
	for (auto &x : all) {
		cnt[x]--;
	}
	
	all.clear();
	reverse(g[cent].begin(), g[cent].end());
	for (auto &u : g[cent]) {
		if (!used[u]) {
			vector<int> vec;
			dfs(u, cent, 0, vec);
			
			for (auto &x : vec) {
				all.push_back(x ^ (1 << (a[cent] - 'a')));
				cnt[x ^ (1 << (a[cent] - 'a'))]++;
			}
		}
	}
	for (auto &x : all) {
		cnt[x]--;
	}
	

	used[cent] = true;
	for (auto &u : g[cent]) {
		if (!used[u]) {
			decomp(u, sz[u]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	decomp(0, n);

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
}