#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = (1 << 17) + 10;

int a[N], t[N << 2];

int build(int i, int b, int e) {
	if (e - b == 1) {
		t[i] = a[b];
		return 1;
	}
	int m = (e + b) >> 1, l = i << 1, r = l | 1;
	int f = build(l, b, m);
	build(r, m, e);
	if (f) {
		t[i] = t[l] | t[r];
	} else {
		t[i] = t[l] ^ t[r];
	}
	return !f;
}
	
int update(int i, int b, int e, int v, int x) {
	if (v < b || e <= v) {
		return -1;
	}
	if (e - b == 1) {
		t[i] = x;
		return 1;
	}
	int m = (e + b) >> 1, l = i << 1, r = l | 1;
	int f = update(l, b, m, v, x);
	int s = update(r, m, e, v, x);
	if (max(f, s)) {
		t[i] = t[l] | t[r];
	} else {
		t[i] = t[l] ^ t[r];
	}
	return !max(f, s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int nn, q;
	cin >> nn >> q;
	int n = 1 << nn;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	build(1, 0, n);

	while (q--) {
		int p, b;
		cin >> p >> b;
		--p;
		update(1, 0, n, p, b);
		cout << t[1] << '\n';
	}
}