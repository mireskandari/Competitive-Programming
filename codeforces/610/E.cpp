#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n, m, k;
string s;

struct Node {
	int mat[10][10], f, l, lz;

	Node() : lz(-1) {}
};

Node t[N << 2];

void apply(int c, int len, int x) {
	memset(t[c].mat, 0, sizeof(t[c].mat));
	t[c].mat[x][x] = len - 1;
	t[c].f = t[c].l = t[c].lz = x;
}

void pull(int c, int l, int r) {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			t[c].mat[i][j] = t[l].mat[i][j] + t[r].mat[i][j];
		}
	}
	t[c].mat[t[l].l][t[r].f]++;
	t[c].f = t[l].f;
	t[c].l = t[r].l;
}

void build(int c, int b, int e) {
	if (e - b == 1) {
		apply(c, 1, s[b] - 'a');
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	pull(c, l, r);
}

void update(int c, int b, int e, int u, int v, int x) {
	if (v <= b || e <= u) {
		return;
	}
	if (u <= b && e <= v) {
		apply(c, e - b, x);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].lz != -1) {
		apply(l, m - b, t[c].lz);
		apply(r, e - m, t[c].lz);
		t[c].lz = -1;
	}
	update(l, b, m, u, v, x);
	update(r, m, e, u, v, x);
	pull(c, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k >> s;
	build(1, 0, n);

	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			char c;
			cin >> l >> r >> c;
			update(1, 0, n, l - 1, r, c - 'a');
		} else {
			string p;
			cin >> p;
			vector<int> pos(k);
			for (int i = 0; i < k; ++i) {
				pos[p[i] - 'a'] = i;
			}
			int ans = 1;
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j < k; ++j) {
					ans += t[1].mat[i][j] * (pos[j] <= pos[i]);
				}
			}
			cout << ans << '\n';
		}
	}
}