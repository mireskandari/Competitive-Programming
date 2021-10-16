#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 3e5 + 10;

int mx[N << 2], lz[N << 2];

void update(int c, int b, int e, int u, int v, int x) {
	if (e <= u || v <= b) {
		return;
	}
	if (u <= b && e <= v) {
		mx[c] += x;
		lz[c] += x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (lz[c] != 0) {
		mx[l] += lz[c];
		lz[l] += lz[c];
		mx[r] += lz[c];
		lz[r] += lz[c];
		lz[c] = 0;
	}
	update(l, b, m, u, v, x);
	update(r, m, e, u, v, x);
	mx[c] = max(mx[l], mx[r]);
}

int p[N], q[N], n, pos[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		pos[p[i]] = i + 1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> q[i];
	}

	int ans = n;
	update(1, 0, n, 0, pos[n], 1);
	for (int i = 0; i < n; ++i) {
		while (mx[1] <= 0) {
			--ans;
			update(1, 0, n, 0, pos[ans], 1);
		}
		update(1, 0, n, 0, q[i], -1);
		cout << ans << ' ';
	}
}