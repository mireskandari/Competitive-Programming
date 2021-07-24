#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 1e6 + 10;

int t1[N << 2], t2[N << 2];

void update1(int c, int b, int e, int u, int v, int x) {
	if (v <= b || e <= u) {
		return;
	}
	if (u <= b && e <= v) {
		t1[c] = x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (~t1[c]) {
		t1[l] = t1[c];
		t1[r] = t1[c];
		t1[c] = -1;
	}
	update1(l, b, m, u, v, x);
	update1(r, m, e, u, v, x);
}

int query1(int c, int b, int e, int u) {
	if (u < b || e <= u) {
		return -1;
	}
	if (e - b == 1) {
		return t1[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (~t1[c]) {
		t1[l] = t1[c];
		t1[r] = t1[c];
		t1[c] = -1;
	}
	return max(query1(l, b, m, u), query1(r, m, e, u));
}

void update2(int c, int b, int e, int u, int x) {
	if (u < b || e <= u) {
		return;
	}
	if (e - b == 1) {
		t2[c] = x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	update2(l, b, m, u, x);
	update2(r, m, e, u, x);
	t2[c] = max(t2[l], t2[r]);
}

int query2(int c, int b, int e, int u, int v) {
	if (e <= u || v <= b) {
		return -1;
	}
	if (u <= b && e <= v) {
		return t2[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	return max(query2(l, b, m, u, v), query2(r, m, e, u, v));
}

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

int n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(t1, -1, sizeof(t1));
	memset(t2, -1, sizeof(t2));

	
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	dfs(0, -1);

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int op, v;
		cin >> op >> v;
		--v;
		if (op == 1) {
			update1(1, 0, n, tin[v], tout[v], i);	
		} else if (op == 2) {
			update2(1, 0, n, tin[v], i);
		} else {
			int q1 = query1(1, 0, n, tin[v]), q2 = query2(1, 0, n, tin[v], tout[v]);
			//cerr << tin[v] << ' ' << tout[v] << ' ' << "ANS: " << q1 << ' ' << q2 << '\n';
			cout << (q1 > q2) << '\n';
		}
	}
}
