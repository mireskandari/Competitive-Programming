#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000 * 1000 * 1000 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int mult(int x, int y) {
	return 1ll * x * y % MOD;
}

constexpr int N = 1e5 + 10;

struct Mat {
	int a[2][2];

	Mat(bool f) {
		memset(a, 0, sizeof(a));
		if (f) {
			a[0][0] = 1;
			a[1][1] = 1;
		}
	}
	
	int* operator[](int x) {
		return a[x];
	}

	Mat operator*(Mat o) {
		Mat res(false);
		for (int i = 0; i < 8; ++i) {
			add(res[i >> 2][(i >> 1) & 1], mult(o[i >> 2][i & 1], a[i & 1][(i >> 1) & 1]));
		}
		return res;
	}

	Mat operator+(Mat o) {
		for (int i = 0; i < 4; ++i) {
			add(o[i >> 1][i & 1], a[i >> 1][i & 1]);
		}
		return o;
	}
};

Mat power(Mat x, int k) {
	Mat res(true);
	for (; k > 0; k >>= 1, x = x * x) {
		if (k & 1) {
			res = res * x;
		}
	}
	return res;
}

struct Node {
	Mat mat, lz;

	Node() : mat(true), lz(true) {}

	void apply(Mat x) {
		mat = mat * x;
		lz = lz * x;
	}
};

Node t[N << 2];

void push(int c, int l, int r) {
	bool have = false;
	for (int i = 0; i < 4; ++i) {
		if (t[c].lz.a[i >> 1][i & 1] != !((i >> 1) ^ (i & 1))) {
			have = true;
			break;
		}
	}
	if (have) {
		t[l].apply(t[c].lz);
		t[r].apply(t[c].lz);
		t[c].lz = Mat(true);
	}
}

void update(int c, int b, int e, int u, int v, Mat x) {
	if (u <= b && e <= v) {
		t[c].apply(x);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	if (u < m) {
		update(l, b, m, u, v, x);
	}
	if (v > m) {
		update(r, m, e, u, v, x);
	}
	t[c].mat = t[l].mat + t[r].mat;
}

int query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c].mat[0][1];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	if (u < m) {
		int x = query(l, b, m, u, v);
		if (v > m) {
			add(x, query(r, m, e, u, v));
		}
		return x;
	}
	return query(r, m, e, u, v);
}

int n, m, a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		Mat mat(false);
		mat[0][0] = mat[0][1] = mat[1][0] = 1;
		update(1, 0, n, i, i + 1, power(mat, a[i]));
	}

	while (m--) {
		int op, l, r;
		cin >> op >> l >> r;
		--l;
		if (op == 1) {
			int x;
			cin >> x;
			Mat mat(false);
			mat[0][0] = mat[0][1] = mat[1][0] = 1;
			update(1, 0, n, l, r, power(mat, x));
		} else {
			cout << query(1, 0, n, l, r) << '\n';
		}
	}
}