#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 777777777;

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

int sub(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

constexpr int N = 2e5 + 10, B = 700499;

int basep[N];
int n, m, x[N], y[N], pos[N];
int t[N << 2], on[N << 2];

void update(int c, int b, int e, int u) {
	if (e - b == 1) {
		if (on[c]) {
			t[c] = 0;
		} else {
			t[c] = y[b];
		}
		on[c] = 1 - on[c];
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (u < m) {
		update(l, b, m, u);
	} else {
		update(r, m, e, u);
	}
	t[c] = add(t[l], mult(t[r], basep[on[l]]));
	on[c] = on[l] + on[r];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	basep[0] = 1;
	for (int i = 1; i < N; ++i) {
		basep[i] = mult(basep[i - 1], B);
	}
	
	cin >> n >> m;
	int hshx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		hshx = add(hshx, mult(basep[i], x[i]));
	}
	for (int i = 0; i < m; ++i) {
		cin >> y[i];
		pos[y[i]] = i;
	}

	for (int i = 1; i <= n; ++i) {
		update(1, 0, m, pos[i]);
	}
	
	int sumbasep = 0;
	for (int i = 0; i < n; ++i) {
		sumbasep = add(sumbasep, basep[i]);
	}

	int ans = 0;
	for (int i = 0; i <= m - n; ++i) {
		if (i == 0) {
			ans += (t[1] == hshx);
		} else {
			update(1, 0, m, pos[i]);
			update(1, 0, m, pos[n + i]);
			ans += (sub(t[1], mult(i, sumbasep)) == hshx);
		}
	}

	cout << ans;
}