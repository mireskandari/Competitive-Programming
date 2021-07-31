#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 1e5 + 10;

struct Node {
	int a;
	int lz;

	Node() : a(0), lz(-1) {}

	void apply(int b, int e, int x) {
		a = (e - b) * x;
		lz = x;
	}
};

struct Seg {
	Node t[N << 2];
	
	void update(int c, int b, int e, int u, int v, int x) {
		if (u <= b && e <= v) {
			t[c].apply(b, e, x);
			return;
		}
		int m = (b + e) >> 1, l = c << 1, r = l | 1;
		if (~t[c].lz) {
			t[l].apply(b, m, t[c].lz);
			t[r].apply(m, e, t[c].lz);
			t[c].lz = -1;
		}
		if (u < m) {
			update(l, b, m, u, v, x);
		}
		if (m < v) {
			update(r, m, e, u, v, x);
		}
		t[c].a = t[l].a + t[r].a;
	}

	int query(int c, int b, int e, int u, int v) {
		if (u <= b && e <= v) {
			return t[c].a;
		}
		int m = (b + e) >> 1, l = c << 1, r = l | 1;
		if (~t[c].lz) {
			t[l].apply(b, m, t[c].lz);
			t[r].apply(m, e, t[c].lz);
			t[c].lz = -1;
		}
		int ret = 0;
		if (u < m) {
			ret += query(l, b, m, u, v);
		}
		if (v > m) {
			ret += query(r, m, e, u, v);
		}
		return ret;
	}
};

Seg t[26];

int n, q;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	cin >> n >> q;
	string s;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		t[s[i] - 'a'].update(1, 0, n, i, i + 1, 1);
	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		--u;
		int mid = (v + u) >> 1;
		int cnt_odd = 0;
		for (int c = 0; c < 26; ++c) {
			int cnt = t[c].query(1, 0, n, u, v);
			cnt_odd += cnt & 1;
		}
		if (cnt_odd > ((v - u) & 1)) {
			continue;
		}
		int uu = u, vv = v;
		for (int c = 0; c < 26; ++c) {
			int cnt = t[c].query(1, 0, n, u, v);
			if (!cnt) {
				continue;
			}
			t[c].update(1, 0, n, u, v, 0);
			if (cnt & 1) {
				t[c].update(1, 0, n, mid, mid + 1, 1);
			}
			if (cnt > 1) {
				t[c].update(1, 0, n, uu, uu + cnt / 2, 1);
				t[c].update(1, 0, n, vv - cnt / 2, vv, 1);
			}
			uu += cnt / 2;
			vv -= cnt / 2;
		}
	}

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < n; ++j) {
			if (t[i].query(1, 0, n, j, j + 1)) {
				s[j] = (char) (i + 'a');
			}
		}
	}

	cout << s;
}