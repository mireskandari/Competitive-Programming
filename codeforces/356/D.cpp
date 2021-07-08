#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 7e4 + 1;

int n, s;
pair<int, int> a[N];
bitset<N> dp, new_dp, diff;
int p[N];
int idx[N];
bool root[N];

vector<int> g[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(p, -1, sizeof(p));
	
	cin >> n >> s;
	int mx = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
		mx = max(mx, a[i].first);
	}

	sort(a, a + n, greater<pair<int, int>>());
	
	if (s < mx) {
		cout << -1;
		exit(0);
	}
	s -= a[0].first;
	root[0] = true;

	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		new_dp = dp | (dp << a[i].first);
		diff = dp ^ new_dp;
		for (int j = diff._Find_first(); j <= s; j = diff._Find_next(j)) {
			p[j] = i;
		}
		swap(new_dp, dp);
	}
		
	if (!dp[s]) {
		cout << -1;
		exit(0);
	}
	
	int v = p[s];
	while (v != -1) {
		s -= a[v].first;
		root[v] = true;
		v = p[s];
	}
	
	
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[i].first == a[j].first) {
			++j;
		}
		int k = i;
		for (int x = i; x < j; ++x) {
			if (root[x]) {
				swap(a[x], a[k++]);
			}
		}
	}
	
	fill(g, g + n, vector<int>{0, 0});
	for (int i = 0, j = 0; i < n; i = j) {
		++j;
		while (j < n && !root[j]) {
			++j;
		}

		for (int x = j - 1; x > i; --x) {
			g[a[x - 1].second][1] = a[x].second;
			g[a[x - 1].second][0] = a[x - 1].first - a[x].first;
		}
		g[a[j - 1].second][0] = a[j - 1].first;
		g[a[j - 1].second].pop_back();
	}
	
	for (int i = 0; i < n; ++i) {
		cout << g[i][0] << ' ' << (len(g[i]) == 2) << ' ';
		if (len(g[i]) == 2) {
			cout << g[i][1] + 1 << '\n';
		} else {
			cout << '\n';
		}
	}
}

