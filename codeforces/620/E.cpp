#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 4e5 + 10;

struct Node {
	long long a;
	int lz;

	Node() : a(0), lz(0) {}

	void apply(int x) {
		a = 1ll << x;
		lz = x;
	}
};

Node t[N << 2];

void update(int c, int b, int e, int u, int v, int x) {
	if (e <= u || v <= b) {
		return;
	}
	if (u <= b && e <= v) {
		t[c].apply(x);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].lz) {
		t[l].apply(t[c].lz);
		t[r].apply(t[c].lz);
		t[c].lz = 0;
	}
	update(l, b, m, u, v, x);
	update(r, m, e, u, v, x);
	t[c].a = t[l].a | t[r].a;
}

long long query(int c, int b, int e, int u, int v) {
	if (e <= u || v <= b) {
		return 0;
	}
	if (u <= b && e <= v) {
		return t[c].a;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].lz) {
		t[l].apply(t[c].lz);
		t[r].apply(t[c].lz);
		t[c].lz = 0;
	}
	return query(l, b, m, u, v) | query(r, m, e, u, v);
}

int n, m;
vector<int> g[N];
int tin[N], tout[N], timer;

void dfs(int v, int p) {
	tin[v] = timer++;
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(u, v);
		}
	}
	tout[v] = timer;
}

int a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	dfs(0, -1);
	
	for (int i = 0; i < n; ++i) {
		update(1, 0, N, tin[i], tin[i] + 1, a[i]);
	}

	while (m--) {
		int op, v;
		cin >> op >> v;
		--v;
		if (op == 1) {
			int x;
			cin >> x;
			update(1, 0, N, tin[v], tout[v], x);
		} else {
			cout << __builtin_popcountll(query(1, 0, N, tin[v], tout[v])) << '\n';
		}
	}
}