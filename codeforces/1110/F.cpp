#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 5e5 + 10;

struct Node {
	long long mn, lz;
	
	void apply(long long x) {
		if (mn == LLONG_MAX) {
			return;
		}
		mn += x;
		lz += x;
	}
};

Node t[N << 2];

void push(int c, int l, int r) {
	if (t[c].lz != 0) {
		t[l].apply(t[c].lz);
		t[r].apply(t[c].lz);
		t[c].lz = 0;
	}
}

void update(int c, int b, int e, int u, int v, long long x) {
	if (e <= u || v <= b) {
		return;
	}
	if (u <= b && e <= v) {
		t[c].apply(x);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	update(l, b, m, u, v, x);
	update(r, m, e, u, v, x);
	t[c].mn = min(t[l].mn, t[r].mn);
}

long long query(int c, int b, int e, int u, int v) {
	if (e <= u || v <= b) {
		return LLONG_MAX;
	}
	if (u <= b && e <= v) {
		return t[c].mn;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	return min(query(l, b, m, u, v), query(r, m, e, u, v));
}

int n, q, qq[N][2];
long long ans[N];
vector<int> qs[N];
vector<pair<int, int>> g[N];
int tin[N], tout[N], timer;
long long dep[N];

void prep(int v, int p) {
	sort(g[v].begin(), g[v].end());
	tin[v] = timer++;
	bool leaf = true;
	for (auto &u : g[v]) {
		if (u.first != p) {
			leaf = false;
			dep[u.first] = dep[v] + u.second;
			prep(u.first, v);
		}
	}
	tout[v] = timer;
	update(1, 0, n, tin[v], tin[v] + 1, leaf ? dep[v] : LLONG_MAX);
}

void dfs(int v, int p) {
	for (auto &qr : qs[v]) {
		ans[qr] = query(1, 0, n, qq[qr][0], qq[qr][1]);
	}
	for (auto &u : g[v]) {
		if (u.first != p) {
			update(1, 0, n, 0, n, u.second);
			update(1, 0, n, tin[u.first], tout[u.first], -1ll * u.second * 2);
			dfs(u.first, v);
			update(1, 0, n, 0, n, -u.second);
			update(1, 0, n, tin[u.first], tout[u.first], 1ll * u.second * 2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		int p, w;
		cin >> p >> w;
		--p;
		g[i].push_back({p, w});
		g[p].push_back({i, w});
	}

	prep(0, -1);
	for (int i = 0; i < q; ++i) {
		int v, l, r;
		cin >> v >> l >> r;
		--v, --l;
		qs[v].push_back(i);
		qq[i][0] = l, qq[i][1] = r;
	}

	dfs(0, -1);
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}