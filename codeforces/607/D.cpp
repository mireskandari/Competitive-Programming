#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

int mult(int a, int b) {
	return 1ll * a * b % MOD;
}

int add(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

int power(int a, int k) {
	int res = 1;
	for (; k; k >>= 1, a = mult(a, a)) {
		if (k & 1) {
			res = mult(res, a);
		}
	}
	return res;
}

constexpr int N = 2e5 + 10;

int t[N << 2], lz[N << 2];

void push(int c, int l, int r) {
	if (lz[c] != 1) {
		t[l] = mult(t[l], lz[c]);
		lz[l] = mult(lz[l], lz[c]);
		t[r] = mult(t[r], lz[c]);
		lz[r] = mult(lz[r], lz[c]);
		lz[c] = 1;
	}
}

void update(int c, int b, int e, int u, int v, int x, bool sett) {
	if (u <= b && e <= v) {
		if (sett) {
			t[c] = x;
			return;
		}
		t[c] = mult(t[c], x);
		lz[c] = mult(lz[c], x);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	if (u < m) {
		update(l, b, m, u, v, x, sett);
	}
	if (v > m) {
		update(r, m, e, u, v, x, sett);
	}
	t[c] = add(t[l], t[r]);
}

int query(int c, int b, int e, int u, int v) {
	if (u >= e || v <= b) {
		return 0;
	}
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	return add(query(l, b, m, u, v), query(r, m, e, u, v));
}

void show(int c, int b, int e) {
	cerr << c << ", " << b + 1 << ", " << e << ": " << t[c] << '\n';
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	show(l, b, m);
	show(r, m, e);
}

int a[N], m, deg[N];
vector<int> g[N];
int tin[N], tout[N], timer;
int q[N];

void dfs(int v, int p) {
	tin[v] = timer++;
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(u, v);
		}
	}
	tout[v] = timer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fill(t, t + (N << 2), 0);
	fill(lz, lz + (N << 2), 1);
	
	cin >> a[0] >> m;
	int n = 1;
	for (int i = 0; i < m; ++i) {
		int op, u;
		cin >> op >> u;
		--u;
		if (op == 1) {
			cin >> a[n];
			g[n].push_back(u);
			g[u].push_back(n);
			q[i] = -u - 1;
			++n;
		} else {
			q[i] = u;
		}
	}

	dfs(0, 0);
	deg[0] = 1;
	update(1, 0, n, tin[0], tin[0] + 1, a[0], true);
	
	int tmpn = 1;
	for (int i = 0; i < m; ++i) {
		int v = q[i];
		//cerr << v << '\n';
		if (v < 0) {
			v = -v - 1;
			//cerr << query(1, 0, n, tin[v], tin[v] + 1) << ' ' << power(a[v], MOD - 2) << '\n';
			int tmp = mult(query(1, 0, n, tin[v], tin[v] + 1), power(a[v], MOD - 2));
			//cerr << "DJSKHDJKSHD " << tmp << '\n';
			deg[tmpn] = 1;
			update(1, 0, n, tin[tmpn], tin[tmpn] + 1, mult(tmp, a[tmpn]), true);
			update(1, 0, n, tin[v], tout[v], power(deg[v], MOD - 2), false);
			deg[v]++;
			update(1, 0, n, tin[v], tout[v], deg[v], false);
			++tmpn;
		} else {
			int coeff = mult(query(1, 0, n, tin[v], tin[v] + 1), power(mult(a[v], deg[v]), MOD - 2));
			coeff = power(coeff, MOD - 2);
			cout << mult(query(1, 0, n, tin[v], tout[v]), coeff) << '\n';
		}
		//show(1, 0, n);
		//cerr << "\n\n\n";
	}
}