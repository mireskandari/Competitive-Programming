#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 3e5 + 10;

int t[N << 2], lz[N << 2];
int m;

void push(int c, int l, int r) {
	if (~lz[c]) {
		t[l] = lz[c];
		lz[l] = lz[c];
		t[r] = lz[c];
		lz[r] = lz[c];
		lz[c] = -1;
	}
}

void update(int c, int b, int e, int u, int v, int x) {
	if (e <= u || v <= b) {
		return;
	}
	if (u <= b && e <= v) {
		t[c] = x;
		lz[c] = x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	update(l, b, m, u, v, x);
	update(r, m, e, u, v, x);
	t[c] = min(t[l], t[r]);
}

int query(int c, int b, int e, int u, int v) {
	if (e <= u || v <= b) {
		return 1e9;
	}
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	return min(query(l, b, m, u, v), query(r, m, e, u, v));
}

int n;
vector<int> g[N], h[N];
int tin[N], tout[N], timer;
int removed[N];
bool mark[N];

void prep(int v, int p) {
	tin[v] = timer++;
	for (auto &u : h[v]) {
		if (u != p) {
			prep(u, v);
		}
	}
	tout[v] = timer;
}

int ans;

void dfs(int v, int p) {
	int now = query(1, 0, n, tin[v], tout[v]);
	//cerr << v << ' ' << now << '\n';
	if (now == (int) 1e9) {
		update(1, 0, n, tin[v], tout[v], v);
		++m;
		removed[v] = -1;
	//	cerr << "KIR1\n";
	} else if (tin[now] <= tin[v] && tout[v] <= tout[now]) {
		update(1, 0, n, tin[now], tout[now], 1e9);
		update(1, 0, n, tin[v], tout[v], v);
		removed[v] = now;
	//	cerr << "KIR2\n";
	} else {
		mark[v] = true;
	//	cerr << "KIR3\n";
	}
	ans = max(ans, m);
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(u, v);
		}
	}
	if (mark[v]) {
		return;
	}
	update(1, 0, n, tin[v], tout[v], 1e9);
	if (~removed[v]) {
		int rm = removed[v];
		update(1, 0, n, tin[rm], tout[rm], rm);
	} else {
		--m;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fill(t, t + n * 4, 1e9);
		fill(lz, lz + n * 4, -1);
		fill(g, g + n, vector<int>());
		fill(h, h + n, vector<int>());
		fill(mark, mark + n, false);
		fill(removed, removed + n, -1);
		timer = 0;
		m = 0;
		ans = 0;
		for (int i = 1; i < n; ++i) {
			int p;
			cin >> p;
			g[i].push_back(--p);
			g[p].push_back(i);
		}
		for (int i = 1; i < n; ++i) {
			int p;
			cin >> p;
			h[i].push_back(--p);
			h[p].push_back(i);
		}
		prep(0, -1);
		dfs(0, -1);
		cout << ans << '\n';
	}
}