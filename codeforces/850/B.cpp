#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

#define int long long

constexpr int maxn = 1e6 + 10;

int n, a[maxn], x, y, cnt[maxn << 1];
long long pref[maxn];

inline long long sum(int l, int r) {
	return !l ? pref[r] : pref[r] - pref[l - 1];
}

inline int lb(int val) {
	return val ? cnt[val - 1] : 0;
}

inline long long solve_range(int l, int r, int g, int up) {
	if (r - l < 0) {
		return 0;
	}
	int low = min(lb(up - min(g, (x + y - 1) / y) + 1), r + 1);

	long long ret = 0;
	if (low < r + 1) {
		ret += 1ll * y * (1ll * up * (r - low + 1) - sum(low, r));
	}
	if (low > l) {
		ret += 1ll * x * (low - l);
	}
	return ret;
}

inline long long solve_g(int g) {
	long long ans_now = 0;

	int high = (a[n - 1] + g - 1) / g;
	high *= g;

	for (int j = g; j <= high; j += g) {
		int l = lb(j - g + 1);
		int r = lb(j) - 1;
		ans_now += solve_range(l, r, g, j);
	}

	return ans_now;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x >> y;
	cerr << 1ll * n * min(x, y);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);
	partial_sum(a, a + n, pref);
	
	for (int i = 0; i < n; ++i) {
		cnt[a[i]]++;
	}
	for (int i = 1; i < (maxn << 1); ++i) {
		cnt[i] += cnt[i - 1];
	}

	long long ans = LLONG_MAX;
	for (int g = 2; g < maxn; ++g) {
		ans = min(ans, solve_g(g));
	}
	
	cout << ans;
}