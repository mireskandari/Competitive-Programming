#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n;
string s;
int coeff[N];
int rnk[20][N], lg;
int p[N];
 
bool cmp(int i, int j) {
	if (rnk[lg - 1][i] != rnk[lg - 1][j]) {
		return rnk[lg - 1][i] < rnk[lg - 1][j];
	}
	i += (1 << (lg - 1));
	j += (1 << (lg - 1));
	if (max(i, j) >= n) {
		return i > j;
	}
	return rnk[lg - 1][i] < rnk[lg - 1][j];
}
 
void build_sa() {
	iota(p, p + n, 0);
	sort(p, p + n, [&](int i, int j) {
		return s[i] < s[j];
	});
	for (int i = 1; i < n; ++i) {
		rnk[lg][p[i]] = rnk[lg][p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
	}
	for (lg = 1; lg < 20; ++lg) {
		sort(p, p + n, cmp);
		for (int i = 1; i < n; ++i) {
			rnk[lg][p[i]] = rnk[lg][p[i - 1]] + cmp(p[i - 1], p[i]);
		}
	}
	--lg;
}

int lcp(int i, int j) {
	int res = 0;
	for (int k = 19; k >= 0; --k) {
		if (max(i, j) + (1 << k) > n) {
			continue;
		}
		if (rnk[k][i] == rnk[k][j]) {
			res += (1 << k);
			i += (1 << k);
			j += (1 << k);
		}
	}
	return res;
}

int a[N], l[N], r[N];

int pref[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		coeff[i] = c - '0';
		coeff[i] = 1 - coeff[i];
	}

	reverse(coeff, coeff + n);
	reverse(s.begin(), s.end());

	build_sa();
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, 1ll * coeff[i] * (n - i));
		pref[i] = coeff[p[i]] + (i ? pref[i - 1] : 0);
	}

	for (int i = 0; i < n - 1; ++i) {
		a[i] = lcp(p[i], p[i + 1]);
		int c = i - 1;
		while (c >= 0 && a[c] >= a[i]) {
			c = l[c];
		}
		l[i] = c;
	}
	for (int i = n - 2; i >= 0; --i) {
		int c = i + 1;
		while (c < n - 1 && a[c] >= a[i]) {
			c = r[c];
		}
		r[i] = c;
		ans = max(ans, 1ll * a[i] * (pref[r[i]] - (l[i] < 0 ? 0 : pref[l[i]])));
	}

	cout << ans;
}