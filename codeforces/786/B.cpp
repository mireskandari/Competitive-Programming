#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1 << 20;

int n_, q, s;
int n, z;
vector<pair<int, int>> g[N];
long long dist[N];

void update(int c, int b, int e, const int u, const int v, const int x, const int w, const bool f) {
	if (v <= b || e <= u) {
		return;
	}
	if (u <= b && e <= v) {
		if (f) {
			g[x].push_back({c, w});
		} else {
			g[c + z].push_back({x + z, w});
		}
		return;
	}
	
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	update(l, b, m, u, v, x, w, f);
	update(r, m, e, u, v, x, w, f);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n_ >> q >> s;
	--s;
	n = 1;
	while (n < n_) {
		n <<= 1;
	}
	z = n << 2;

	for (int i = n - 1; i >= 1; --i) {
		g[i].push_back({i << 1, 0});
		g[i].push_back({i << 1 | 1, 0});
		g[(i << 1) + z].push_back({i + z, 0});
		g[(i << 1 | 1) + z].push_back({i + z, 0});
	}
	for (int i = 0; i < n; ++i) {
		g[i + n].push_back({i + n + z, 0});
		g[i + n + z].push_back({i + n, 0});
	}

	while (q--) {
		int t;
		cin >> t;
		int v, l, r;
		cin >> v >> l;
		r = l;
		if (t >= 2) {
			cin >> r;
		}
		--l;
		--v;
		int w;
		cin >> w;
		update(1, 0, n, l, r, v + n, w, t <= 2);
	}

	memset(dist, 0x3f, sizeof(dist));
	set<pair<long long, int>> st;
	st.insert({0, s + n});
	dist[s + n] = 0;

	while (!st.empty()) {
		int v = st.begin()->second;
		long long d = st.begin()->first;
		st.erase(st.begin());
		for (auto &e : g[v]) {
			if (dist[e.first] > d + e.second) {
				st.erase({dist[e.first], e.first});
				dist[e.first] = d + e.second;
				st.insert({dist[e.first], e.first});
			}
		}
	}

	for (int i = 0; i < n_; ++i) {
		cout << (dist[i + n] >= 1e18 && dist[i + n + z] >= 1e18 ? -1ll : min(dist[i + n], dist[i + n + z])) << ' ';
	}
}