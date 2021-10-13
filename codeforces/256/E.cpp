#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MD = 777777777;

void add(int &a, int b) {
	a += b;
	if (a >= MD) {
		a -= MD;
	}
}

int mult(int a, int b) {
	return 1ll * a * b % MD;
}

constexpr int N = 2e5 + 10, K = 3;

int n, m, good[K][K];
vector<pair<int, int>> good_pairs;
int t[N << 2][K][K];

void pull(int c, int l, int r) {
	memset(t[c], 0, sizeof(t[c]));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (auto &p : good_pairs) {
				add(t[c][i][j], mult(t[l][i][p.first], t[r][p.second][j]));
			}
		}
	}
}

void build(int c, int b, int e) {
	if (e - b == 1) {
		for (int i = 0; i < 3; ++i) {
			t[c][i][i] = 1;
		}
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	pull(c, l, r);
}

void update(int c, int b, int e, int u, int x) {
	if (e - b == 1) {
		memset(t[c], 0, sizeof(t[c]));
		if (~x) {
			t[c][x][x] = 1;
		} else {
			for (int i = 0; i < 3; ++i) {
				t[c][i][i] = 1;
			}
		}
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (u < m) {
		update(l, b, m, u, x);
	} else {
		update(r, m, e, u, x);
	}
	pull(c, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int x;
			cin >> x;
			if (x) {
				good_pairs.push_back({i, j});
			}
		}
	}

	build(1, 0, n);
	
	while (m--) {
		int v, x;
		cin >> v >> x;
		--v, --x;
		update(1, 0, n, v, x);
		int ans = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				add(ans, t[1][i][j]);
			}
		}
		cout << ans << '\n';
	}
}