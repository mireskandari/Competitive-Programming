#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 5e5 + 10;

int n, bro[22][N];
int a[N], last[N];

void build(int c, int b, int e, int d) {
	for (int i = b; i < e; ++i) {
		bro[d][i] = last[i];
	}
	sort(bro[d] + b, bro[d] + e);
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m, d + 1);
	build(r, m, e, d + 1);
}

int query(int c, int b, int e, int u, int v, int d) {
	if (e <= u || v <= b) {
		return 0;
	}
	if (u <= b && e <= v) {
		assert(u - 1 >= 0);
		auto p = upper_bound(bro[d] + b, bro[d] + e, u - 1);
		return p == bro[d] + b ? 0 : *(p - 1);
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	return max(query(l, b, m, u, v, d + 1), query(r, m, e, u, v, d + 1));
}

int dp[N];
pair<int, int> par[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	map<int, int> ll;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (ll.find(a[i]) != ll.end()) {
			last[i] = ll[a[i]];
		}
		ll[a[i]] = i;
	}

	build(1, 1, n + 1, 0);

	dp[0] = 0;
	par[0] = {-1, -1};
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		par[i] = {-1, -1};
		int y = query(1, 1, n + 1, last[i] + 1, i, 0);
		if (y && dp[y - 1] + 4 > dp[i]) {
			dp[i] = dp[y - 1] + 4;
			par[i] = {i, y};
		}
		int x = i, c = 3;
		while (c > 0) {
			c--;
			x = last[x];
		}
		if (x && dp[x - 1] + 4 > dp[i]) {
			dp[i] = dp[x - 1] + 4;
			par[i] = {i, x};
		}
	}
	
	cout << dp[n] << '\n';
	int x = n;
	vector<int> ans;
	while (x > 0) {
		if (par[x].first == -1) {
			x--;
			continue;
		}
		int i = par[x].first, j = par[x].second;
		ans.push_back(a[i]);
		ans.push_back(a[j]);
		ans.push_back(a[i]);
		ans.push_back(a[j]);
		x = j - 1;
	}
	reverse(ans.begin(), ans.end());
	for (auto &k : ans) {
		cout << k << ' ';
	}
}