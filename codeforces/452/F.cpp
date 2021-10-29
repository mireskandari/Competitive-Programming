#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 1000000037, B = 98765431;

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

constexpr int N = 3e5 + 10;

struct Node {
	int rev, org, sz;
};

Node t[N << 2];

int n, pw[N];
bool a[N];

void update(int c, int b, int e, int u) {
	if (u < b || u >= e) {
		return;
	}
	if (e - b == 1) {
		t[c].org = t[c].rev = a[b];
		t[c].sz = 1;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	update(l, b, m, u);
	update(r, m, e, u);
	t[c].sz = t[l].sz + t[r].sz;
	t[c].org = add(t[l].org, mult(t[r].org, pw[t[l].sz]));
	t[c].rev = add(t[r].rev, mult(t[l].rev, pw[t[r].sz]));
}

Node query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (u < m) {
		if (v > m) {
			Node res, ll = query(l, b, m, u, v), rr = query(r, m, e, u, v);
			res.sz = ll.sz + rr.sz;
			res.org = add(ll.org, mult(rr.org, pw[ll.sz]));
			res.rev = add(rr.rev, mult(ll.rev, pw[rr.sz]));
			return res;
		} else {
			return query(l, b, m, u, v);
		}
	} else {
		return query(r, m, e, u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	pw[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw[i] = mult(pw[i - 1], B);
	}

	cin >> n;
	vector<int> b(n);
	bool good = false;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		--b[i];
		if (b[i] != 0 && b[i] != n - 1) {
			int sz = min(b[i], n - b[i] - 1);
			good |= query(1, 0, n, b[i] - sz, b[i]).org != query(1, 0, n, b[i] + 1, b[i] + 1 + sz).rev;
		}
		a[b[i]] = true;
		update(1, 0, n, b[i]);
	}
	
	cout << (good ? "YES" : "NO");
}