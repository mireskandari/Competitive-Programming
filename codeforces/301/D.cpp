#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 2e5 + 10;

int t[N << 2];

void update(int c, int b, int e, int u, int x) {
	if (e - b == 1) {
		t[c] += x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (u < m) {
		update(l, b, m, u, x);
	}
	if (u >= m) {
		update(r, m, e, u, x);
	}
	t[c] = t[l] + t[r];
}

int query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	int ret = 0;
	if (u < m) {
		ret += query(l, b, m, u, v);
	}
	if (v > m) {
		ret += query(r, m, e, u, v);
	}
	return ret;
}

int n, m, ans[N];
int a[N], loc[N];
vector<int> p[N];
vector<pair<int, int>> qs[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		loc[a[i]] = i;
	}
	
	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		qs[r].push_back({l, i});
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			if (loc[i] < loc[j]) {
				p[loc[j]].push_back(loc[i]);
			} else {
				p[loc[i]].push_back(loc[j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (auto &l : p[i]) {
			update(1, 1, n + 1, l, 1);
		}
		for (auto &pr : qs[i]) {
			ans[pr.second] += query(1, 1, n + 1, pr.first, i + 1);
		}
	}

	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << '\n';
	}
}