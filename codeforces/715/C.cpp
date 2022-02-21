#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int mod;

int ok(int x) {
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int mult(int a, int b) {
	return 1ll * a * b % mod;
}

pair<int, int> mygcd(int x, int y) {
	if (!y) {
		return make_pair(1, 0);
	}
	int f, s;
	tie(f, s) = mygcd(y, x % y);
	return make_pair(s, f - s * (x / y));
}

int pw[N], inv[N], sz[N];
bool used[N];
int n, dep[N];
vector<pair<int, int>> g[N];
vector<int> vec;
map<int, int> cnt;
long long ans;

int dfs(int v, int p, int x, int y) {
	sz[v] = 1;
	int ret = !x; // from centroid
	ret += !y; // to centroid
	
	vec.push_back(x);
	ans += cnt[mult(mod - y, inv[dep[v]])];

	for (auto &e : g[v]) {
		int u = e.first, w = e.second;
		if (u != p && !used[u]) {
			dep[u] = dep[v] + 1;
			ret += dfs(u, v, ok(mult(pw[dep[v]], w) + x), ok(w + mult(pw[1], y)));
			sz[v] += sz[u];
		}
	}
	return ret;
}

void solve(int c) {
	for (auto &e : g[c]) {
		int u = e.first, w = e.second;
		if (!used[u]) {
			dep[u] = 1;
			ans += dfs(u, c, w, w);
			for (auto &x : vec) {
				cnt[x]++;
			}
			vec.clear();
		}
	}
	map<int, int>().swap(cnt);
	reverse(g[c].begin(), g[c].end());
	for (auto &e : g[c]) {
		int u = e.first, w = e.second;
		if (!used[u]) {
			dfs(u, c, w, w);
			for (auto &x : vec) {
				cnt[x]++;
			}
			vec.clear();
		}
	}
	map<int, int>().swap(cnt);
}

int centroid(int v, int p, int m) {
	int ret = 0, cool = 1;
	sz[v] = 1;
	for (auto &e : g[v]) {
		int u = e.first;
		if (u != p && !used[u]) {
			ret ^= ~centroid(u, v, m);
			cool &= sz[u] <= m >> 1;
			sz[v] += sz[u];
		}
	}
	return cool && m - sz[v] <= m >> 1 ? v : ~ret;
}

void decompose(int v, int m) {
	int c = centroid(v, -1, m);
	solve(c);
	used[c] = true;
	for (auto &e : g[c]) {
		int u = e.first;
		if (!used[u]) {
			decompose(u, sz[u]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> mod;
	
	pw[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw[i] = mult(pw[i - 1], 10);
	}
	inv[N - 1] = mygcd(pw[N - 1], mod).first;
	inv[N - 1] = (inv[N - 1] + mod) % mod;
	for (int i = N - 1; i > 0; --i) {
		inv[i - 1] = mult(inv[i], 10);
	}

	for (int i = 0; i < n - 1; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		w %= mod;
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}

	decompose(0, n);

	cout << ans;
}