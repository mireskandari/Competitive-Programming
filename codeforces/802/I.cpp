#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int n;
string s;
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
	lg = 0;
	rnk[lg][p[0]] = 0;
	for (int i = 1; i < n; ++i) {
		rnk[lg][p[i]] = rnk[lg][p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
	}
	for (lg = 1; lg < 20; ++lg) {
		sort(p, p + n, cmp);
		rnk[lg][p[0]] = 0;
		for (int i = 1; i < n; ++i) {
			rnk[lg][p[i]] = rnk[lg][p[i - 1]] + cmp(p[i - 1], p[i]);
		}
	}
	--lg;
}

int lcp(int i, int j) {
	int ret = 0;
	for (int x = lg; x >= 0; --x) {
		if ((1 << x) + max(i, j) > n) {
			continue;
		}
		if (rnk[x][i] == rnk[x][j]) {
			ret += 1 << x;
			i += 1 << x;
			j += 1 << x;
		}
	}
	return ret;
}

int l[N], r[N], d[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;

	while (tc--) {
		cin >> s;
		n = (int) s.size();

		build_sa();
		
		for (int i = 0; i < n - 1; ++i) {
			d[i] = lcp(p[i], p[i + 1]);
			int c = i - 1;
			while (~c && d[c] > d[i]) {
				c = l[c];
			}
			l[i] = c;
		}
		long long ans = 0;
		for (int i = n - 2; i >= 0; --i) {
			int c = i + 1;
			while (c < n - 1 && d[c] >= d[i]) {
				c = r[c];
			}
			r[i] = c;
			
			//cerr << i << ' ' << d[i] << ' ' << l[i] << ' ' << c << '\n';
			ans += 1ll * d[i] * (i - l[i]) * (c - i);
		}
		ans *= 2;
		ans += 1ll * n * (n + 1) / 2;
		cout << ans << '\n';
	}
}