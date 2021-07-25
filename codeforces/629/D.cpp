#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 1e5 + 10;

long long t[N << 2];

void update(int c, int b, int e, int i, long long x) {
	if (e - b == 1) {
		t[c] = x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (i < m) {
		update(l, b, m, i, x);
	}
	if (i >= m) {
		update(r, m, e, i, x);
	}
	t[c] = max(t[l], t[r]);
}

long long query(int c, int b, int e, int u, int v) {
	if (u >= e || v <= b) {
		return 0;
	}
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	return max(query(l, b, m, u, v), query(r, m, e, u, v));
}

const long double PI = acos(-1);

int n;
long long dp[N];
pair<long long, int> a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int r, h;
		cin >> r >> h;
		a[i] = {1ll * r * r * h, i};
	}

	sort(a, a + n);
	
	long double ans = 0;
	
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[i].first == a[j].first) {
			++j;
		}
		for (int k = i; k < j; ++k) {
			dp[k] = max(query(1, 0, n, 0, a[k].second) + a[k].first, a[k].first);
		}
		for (int k = i; k < j; ++k) {
			ans = max(ans, PI * dp[k]);
			update(1, 0, n, a[k].second, dp[k]);
		}
	}

	cout << fixed << setprecision(9) << ans;
}