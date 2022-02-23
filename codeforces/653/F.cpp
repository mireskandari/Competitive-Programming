#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 5e5 + 10;

string s;
int n;
int rnk[20][N], p[N];
int ll;

bool cmp(int i, int j) {
	if (rnk[ll - 1][i] != rnk[ll - 1][j]) {
		return rnk[ll - 1][i] < rnk[ll - 1][j];
	}
	i += 1 << (ll - 1);
	j += 1 << (ll - 1);
	if (max(i, j) >= n) {
		return i > j;
	}
	return rnk[ll - 1][i] < rnk[ll - 1][j];
}

void build_sa() {
	iota(p, p + n, 0);
	sort(p, p + n, [&](int i, int j) {
		return s[i] < s[j];
	});
	for (int i = 1; i < n; ++i) {
		rnk[0][p[i]] = rnk[0][p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
	}
	for (ll++; ll < 20; ++ll) {
		sort(p, p + n, cmp);
		for (int i = 1; i < n; ++i) {
			rnk[ll][p[i]] = rnk[ll][p[i - 1]] + cmp(p[i - 1], p[i]);
		}
	}
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

int pref[N], mn[20][N];

void build_mn() {
	for (int i = 0; i < n; ++i) {
		pref[i] = (i ? pref[i - 1] : 0) + (s[i] == '(' ? 1 : -1);
		mn[0][i] = pref[i];
	}
	for (int k = 1; k < 20; ++k) {
		for (int i = 0; i + (1 << k) <= n; ++i) {
			mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + (1 << (k - 1))]);
		}
	}
}

int goodlen(int i) {
	int res = 0, j = i;
	for (int k = 19; k >= 0; --k) {
		if (i + (1 << k) > n) {
			continue;
		}
		if (mn[k][i] - (j ? pref[j - 1] : 0) >= 0) {
			i += (1 << k);
			res += (1 << k);
		}
	}
	return res;
}

vector<pair<int, int>> query[N];

int cnt[N << 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> s;

	build_mn();
	build_sa();
	
	int last = -1;
	for (int i = 0; i < n; ++i) {
		int x = ~last ? lcp(last, p[i]) : 0;
		last = p[i];
		int y = goodlen(p[i]);
		if (y > x) {
			int j = p[i];
			int k = j ? pref[j - 1] : 0;
			if (j + x - 1 >= 0) {
				query[j + x - 1].push_back({k, -1});
			}
			if (j + y - 1 >= 0) {
				query[j + y - 1].push_back({k, +1});
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		cnt[pref[i] + N]++;
		for (auto &q : query[i]) {
			ans += 1ll * q.second * cnt[q.first + N];
		}
	}
	
	cout << ans;
}