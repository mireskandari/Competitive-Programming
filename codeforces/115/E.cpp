#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
#define int long long
constexpr int N = 2e5 + 10;

long long lz[N << 2], mx[N << 2];

void push(int c, int l, int r) {
	if (lz[c] != 0) {
		lz[l] += lz[c];
		mx[l] += lz[c];
		lz[r] += lz[c];
		mx[r] += lz[c];
		lz[c] = 0;
	}
}

void update(int c, int b, int e, int u, int v, int x) {
	if (b >= v || e <= u) {
		return;
	}
	if (u <= b && e <= v) {
		mx[c] += x;
		lz[c] += x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	update(l, b, m, u, v, x);
	update(r, m, e, u, v, x);
	mx[c] = max(mx[l], mx[r]);
}

long long query(int c, int b, int e, int u, int v) {
	if (u >= e || v <= b) {
		return -9e18;
	}
	if (u <= b && e <= v) {
		return mx[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, l, r);
	return max(query(l, b, m, u, v), query(r, m, e, u, v));
}

int n, m, rd[N], rc[N][3];
vector<int> endd[N];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> rd[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> rc[i][0] >> rc[i][1] >> rc[i][2];
		endd[rc[i][1]].push_back(i);
	}
	
	for (int i = 1; i <= n; ++i) {
		update(1, 0, n + 1, i, i + 1, query(1, 0, n + 1, 0, i));
		update(1, 0, n + 1, 0, i, -rd[i]);
		for (auto &j : endd[i]) {
			update(1, 0, n + 1, 0, rc[j][0], rc[j][2]);
		}
		//cerr << qmax(1, 0, n + 1, i) << '\n';;
	}

	cout << mx[1];
}