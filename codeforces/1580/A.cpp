#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 410;

int n, m, a[N][N], pref[N][N], mid[N][N], last[N][N];

int lz[N << 2], t[N << 2];

void sett(int c, int b, int e, int u, int x) {
	if (e - b == 1) {
		t[c] = x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (lz[c]) {
		lz[l] += lz[c];
		t[l] += lz[c];
		lz[r] += lz[c];
		t[r] += lz[c];
		lz[c] = 0;
	}
	if (u < m) {
		sett(l, b, m, u, x);
	}
	if (u >= m) {
		sett(r, m, e, u, x);
	}
	t[c] = min(t[l], t[r]);
}

void update(int c, int b, int e, int u, int v, int x) {
	if (u <= b && e <= v) {
		lz[c] += x;
		t[c] += x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (lz[c]) {
		lz[l] += lz[c];
		t[l] += lz[c];
		lz[r] += lz[c];
		t[r] += lz[c];
		lz[c] = 0;
	}
	if (u < m) {
		update(l, b, m, u, v, x);
	}
	if (v > m) {
		update(r, m, e, u, v, x);
	}
	t[c] = min(t[l], t[r]);
}

int query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (lz[c]) {
		lz[l] += lz[c];
		t[l] += lz[c];
		lz[r] += lz[c];
		t[r] += lz[c];
		lz[c] = 0;
	}
	int ret = INT_MAX;
	if (u < m) {
		ret = query(l, b, m, u, v);
	}
	if (v > m) {
		ret = min(ret, query(r, m, e, u, v));
	}
	return ret;
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				char c;
				cin >> c;
				a[i][j] = c - '0';
				pref[i][j] = a[i][j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				pref[i][j] += pref[i - 1][j];
			}
		}
		
		int ans = INT_MAX;
		for (int w = 5; w <= n; ++w) {
			for (int i = w; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					last[i][j] = (w - 2) - pref[i - 1][j] + pref[i - w + 1][j];
					mid[i][j] = pref[i - 1][j] - pref[i - w + 1][j] + (1 - a[i - w + 1][j]) + (1 - a[i][j]);
					//cerr << "SUM: " << i << ' ' << j << ' ' << mid[i][j] << '\n';
					//cerr << "LAST: " << i << ' ' << j << ' ' << last[i][j] << '\n';
				}
				int prv = last[i][1] + mid[i][2] + mid[i][3];
				for (int j = 4; j <= m; ++j) {
						//cerr << w << ' ' << i << ' ' << j << ' ' << query(1, 1, m + 1, 1, j) << '\n';
					ans = min(ans, prv + last[i][j]);
					prv = min(prv + mid[i][j], last[i][j - 2] + mid[i][j - 1] + mid[i][j]);
				}
			}
		}

		cout << ans << '\n';
	}
}