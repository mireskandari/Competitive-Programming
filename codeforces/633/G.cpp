#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n, m, a[N];

bitset<1000> normer;

struct Node {
	bitset<1000> mark;
	int lz;

	inline void apply(int x) {
		mark = ((mark << x) & normer) ^ (mark >> (m - x));
		lz += x;
		if (lz >= m) {
			lz -= m;
		}
	}
};

Node t[N << 2];

void update(int c, int b, int e, int u, int v, int x) {
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
	if (u < m) {
		update(l, b, m, u, v, x);
	}
	if (v > m) {
		update(r, m, e, u, v, x);
	}
	t[c].mark = t[l].mark | t[r].mark;
}

bitset<1000> query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c].mark;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].lz) {
		t[l].apply(t[c].lz);
		t[r].apply(t[c].lz);
		t[c].lz = 0;
	}
	bitset<1000> ret(0);
	if (u < m) {
		ret |= query(l, b, m, u, v);
	}
	if (v > m) {
		ret |= query(r, m, e, u, v);
	}
	return ret;
}


vector<int> g[N];
int tin[N], tout[N], timer, invtin[N];

void dfs(int v, int p) {
	tin[v] = timer++;
	invtin[tin[v]] = v;
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(u, v);
		}
	}
	tout[v] = timer;
}

void build(int c, int b, int e) {
	if (e - b == 1) {
		t[c].mark[a[invtin[b]] % m] = 1;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	t[c].mark = t[l].mark | t[r].mark;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		normer[i] = 1;
	}

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	
	vector<int> primes;
	for (int i = 2; i < m; ++i) {
		bool ok = true;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			primes.push_back(i);
		}
	}
	
	build(1, 0, n);

	int q;
	cin >> q;
	while (q--) {
		int op, v;
		cin >> op >> v;
		--v;
		if (op == 1) {
			int x;
			cin >> x;
			x %= m;
			update(1, 0, n, tin[v], tout[v], x);
		} else {
			auto ret = query(1, 0, n, tin[v], tout[v]);
			int cnt = 0;
			for (auto &p : primes) {
				cnt += ret[p];
			}
			cout << cnt << '\n';
		}
	}	
}