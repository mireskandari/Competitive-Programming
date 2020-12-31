#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mxn = 1e6 + 10, mod = 1000 * 1000 * 1000 + 7;

int mult(int a, int b) {
	return 1ll * a * b % mod;
}

int power(int a, int b) {
	int res = 1;
	for (; b > 0; b >>= 1, a = mult(a, a)) {
		if (b & 1) {
			res = mult(res, a);
		}
	}
	return res;
}

int n, m, guys[mxn];

int root(int v) {
	return guys[v] < 0 ? v : guys[v] = root(guys[v]);
}

bool unite(int v, int u) {
	v = root(v), u = root(u);
	if (v == u) {
		return false;
	}
	guys[v] += guys[u];
	guys[u] = v;
	return true;
}

int main() {
	memset(guys, -1, sizeof(guys));
	scanf("%d%d", &m, &n);
	vector<int> edges;
	for (int i = 0; i < m; ++i) {
		int sz, v, u;
		scanf("%d%d", &sz, &v);
		--v;
		if (sz == 2) {
			scanf("%d", &u);
			--u;
		} else {
			u = n;
		}
		if (unite(u, v)) {
			edges.push_back(i);
		}
	}
	++n;
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		if (guys[i] < 0) {
			ans = mult(ans, power(2, -guys[i] - 1));
		}
	}
	printf("%d %d\n", ans, len(edges));
	for (auto &e : edges) {
		printf("%d ", e + 1);
	}
	return 0;
}

