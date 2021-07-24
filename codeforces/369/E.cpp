#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 1e6 + 10;

int t[N << 2];

void update(int c, int b, int e, int u, int x) {
	if (e - b == 1) {
		t[c] += x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (b <= u && u < m) {
		update(l, b, m, u, x);
	}
	if (m <= u && u < e) {
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

int n, m;
vector<int> a[N];
vector<pair<int, int>> qs[N];
int ans[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int r, l;
		cin >> l >> r;
		a[r].push_back(l);
	}
	
	for (int i = 0; i < m; ++i) {
		ans[i] = n;
		int k;
		cin >> k;
		int f = 0;
		for (int j = 0; j < k; ++j) {
			int last = f;
			cin >> f;
			qs[f].push_back({last, i});
		}
		qs[N - 1].push_back({f, i});
	}
	
	for (int i = 0; i < N - 1; ++i) {
		for (auto &l : a[i]) {
			update(1, 0, N, l, 1);
		}
		for (auto &pr : qs[i + 1]) {
			ans[pr.second] -= query(1, 0, N, pr.first + 1, i + 1);
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}