#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

struct Node {
	int mn_l, mx_r;
	bool bad;

	Node() : mn_l((int) 1e9), mx_r((int) -1e9) {}
};

Node t[N << 2];

void update(int c, int b, int e, int u, bool is_l, int val) {
	if (e - b == 1) {
		if (is_l) {
			t[c].mn_l = val;
		} else {
			t[c].mx_r = val;
		}
		t[c].bad = t[c].mn_l <= t[c].mx_r;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (u < m) {
		update(l, b, m, u, is_l, val);
	} else {
		update(r, m, e, u, is_l, val);
	}
	t[c].mn_l = min(t[l].mn_l, t[r].mn_l);
	t[c].mx_r = max(t[l].mx_r, t[r].mx_r);
	t[c].bad = t[l].bad || t[r].bad || t[l].mn_l <= t[r].mx_r;
}

int n, m, q;
set<int> rowl[N], rowr[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> q;
	for (int i = 0; i < N; ++i) {
		rowl[i].insert(1e9);
		rowr[i].insert(-1e9);
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (!(x & 1)) {
			if (rowl[x >> 1].find(y >> 1) != rowl[x >> 1].end()) {
				rowl[x >> 1].erase(y >> 1);
			} else {
				rowl[x >> 1].insert(y >> 1);
			}
			update(1, 0, n, x >> 1, true, *rowl[x >> 1].begin());
		} else {
			if (rowr[x >> 1].find(y >> 1) != rowr[x >> 1].end()) {
				rowr[x >> 1].erase(y >> 1);
			} else {
				rowr[x >> 1].insert(y >> 1);
			}
			update(1, 0, n, x >> 1, false, *rowr[x >> 1].rbegin());
		}
		cout << (t[1].bad ? "NO" : "YES") << '\n';
	}
}