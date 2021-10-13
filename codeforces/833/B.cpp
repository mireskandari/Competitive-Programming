#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int NINF = -1e7;
constexpr int N = 35010, K = 55;

struct Node {
	int mx, lz;

	Node() : mx(NINF), lz(0) {}
};

Node t[K][N << 2];

void push(int i, int c, int l, int r) {
	if (t[i][c].lz != 0) {
		t[i][l].mx += t[i][c].lz;
		t[i][l].lz += t[i][c].lz;
		t[i][r].mx += t[i][c].lz;
		t[i][r].lz += t[i][c].lz;
		t[i][c].lz = 0;
	}
}

void update(int i, int c, int b, int e, int u, int v, int x) {
	if (u <= b && e <= v) {
		t[i][c].mx += x;
		t[i][c].lz += x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(i, c, l, r);
	if (u < m) {
		update(i, l, b, m, u, v, x);
	}
	if (v > m) {
		update(i, r, m, e, u, v, x);
	}
	t[i][c].mx = max(t[i][l].mx, t[i][r].mx);
}

int query(int i, int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[i][c].mx;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(i, c, l, r);
	int ret = NINF;
	if (u < m) {
		ret = query(i, l, b, m, u, v);
	}
	if (v > m) {
		ret = max(ret, query(i, r, m, e, u, v));
	}
	return ret;
}

int n, k, a[N], pos[N], dp[N][K];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	fill(&dp[0][0], &dp[N - 1][K - 1] + 1, NINF);

	dp[1][1] = 1;
	pos[a[1]] = 1;
	update(1, 1, 1, n + 1, 1, 2, -NINF + 1);

	for (int i = 2; i <= n; ++i) {
		dp[i][1] = dp[i - 1][1] + (pos[a[i]] == 0);
		update(1, 1, 1, n + 1, i, i + 1, -NINF + dp[i][1]);
		for (int j = 1; j < k; ++j) {
			if (pos[a[i]] < i) {
				update(j, 1, 1, n + 1, pos[a[i]], i, 1);
			}
			dp[i][j + 1] = query(j, 1, 1, n + 1, 1, i);
			update(j + 1, 1, 1, n + 1, i, i + 1, -NINF + dp[i][j + 1]);
		}
		pos[a[i]] = i;
	}
	
	cout << dp[n][k];
}