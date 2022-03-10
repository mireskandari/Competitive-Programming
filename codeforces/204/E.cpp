// get rekt noob
#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int n, k, ll, len[N], all;
string s[N], f;
int p[N];
int who[N];
int start[N];
int rnk[20][N];

bool cmp(int i, int j) {
	if (rnk[ll][i] != rnk[ll][j]) {
		return rnk[ll][i] < rnk[ll][j];
	}
	int x = start[who[i]] + len[who[i]], y = start[who[j]] + len[who[j]];
	i += (1 << ll);
	j += (1 << ll);
	if (min(x - i, y - j) <= 0) {
		return x - i < y - j;
	}
	return rnk[ll][i] < rnk[ll][j];
}

void suffix_array() {
	iota(p, p + all, 0);
	sort(p, p + all, [&](int i, int j) {
		return f[i] < f[j];
	});
	for (int i = 1; i < all; ++i) {
		rnk[0][p[i]] = rnk[0][p[i - 1]] + (f[p[i]] != f[p[i - 1]]);
	}
	for (; ll < 19; ++ll) {
		sort(p, p + all, cmp);
		for (int i = 1; i < all; ++i) {
			rnk[ll + 1][p[i]] = rnk[ll + 1][p[i - 1]] + cmp(p[i - 1], p[i]);
		}
	}
}

int lcp(int i, int j) {
	int res = 0;
	int x = start[who[i]] + len[who[i]], y = start[who[j]] + len[who[j]];
	for (int k = 19; k >= 0; --k) {
		if (min(x - i, y - j) < (1 << k)) {
			continue;
		}
		if (rnk[k][i] == rnk[k][j]) {
			i += (1 << k);
			j += (1 << k);
			res += (1 << k);
		}
	}
	return res;
}

int mn[20][N];

void build_bullshit() {
	for (int i = 0; i < all - 1; ++i) {
		mn[0][i] = lcp(p[i], p[i + 1]);
	}
	for (int k = 1; k < 20; ++k) {
		for (int i = 0; i + (1 << k) <= all - 1; ++i) {
			mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + (1 << (k - 1))]);
		}
	}
}

int solveright(int i, int x) {
	for (int k = 19; k >= 0; --k) {
		if (i + (1 << k) > all - 1) {
			continue;
		}
		if (mn[k][i] >= x) {
			i += (1 << k);
		}
	}
	return i;
}

int solveleft(int i, int x) {
	for (int k = 19; k >= 0; --k) {
		if (i - (1 << k) < 0) {
			continue;
		}
		if (mn[k][i - (1 << k)] >= x) {
			i -= (1 << k);
		}
	}
	return i;
}

int dp[N];

void solve_dp() {
	map<int, int> mp;
	int ptr = 0;
	for (int i = 0; i < all; ++i) {
		int x = p[i];
		mp[who[x]]++;
		while (ptr < i && ((int) mp.size() > k || ((int) mp.size() == k && mp[who[p[ptr]]] > 1))) {
			int tt = who[p[ptr]];
			if (--mp[tt] == 0) {
				mp.erase(tt);
			}
			++ptr;
		}
		if ((int) mp.size() == k) {
			dp[i] = ptr;
		} else {
			dp[i] = -1;
		}
	}
}

bool check(int i, int x) {
	int lft = solveleft(i, x), rght = solveright(i, x);
	if (dp[rght] == -1) {
		return false;
	}
	return lft <= dp[rght];
}

long long ans[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		start[i] = all;
		len[i] = (int) s[i].size();
		for (auto &c : s[i]) {
			f += c;
			who[all++] = i;
		}	
	}

	suffix_array();
	build_bullshit();
	solve_dp();

	for (int i = 0; i < all; ++i) {
		int x = p[i];
		int low = 0, high = len[who[x]] + start[who[x]] - x;
		while (high - low > 0) {
			int mid = (low + high + 1) >> 1;
			if (check(i, mid)) {
				low = mid;
			} else {
				high = mid - 1;
			}
		}
		ans[who[x]] += low;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
}