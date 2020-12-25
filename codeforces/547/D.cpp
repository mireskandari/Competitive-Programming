#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mxn = 1e6 + 10;

vector<pair<int, int>> g[mxn];
bool emark[mxn], mark[mxn];
vector<int> tour;

void dfs(int v, int pi) {
	mark[v] = true;
	while (!g[v].empty()) {
		int u = g[v].back().first, i = g[v].back().second;
		g[v].pop_back();
		if (emark[i]) {
			continue;
		}
		emark[i] = true;
		dfs(u, i);
	}
	if (pi > 0) {
		tour.push_back(pi);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		y += (int) 2e5 + 10;
		g[x].push_back({y, i});
		g[y].push_back({x, i});
	}
	vector<int> odds;
	for (int i = 0; i < mxn; ++i) {
		if (len(g[i]) & 1) {
			odds.push_back(i);
		}
	}
	for (int i = n + 1; !odds.empty(); ++i) {
		int v = odds.back(), u = odds[len(odds) - 2];
		odds.resize(len(odds) - 2);
		g[v].push_back({u, i});
		g[u].push_back({v, i});
	}
	vector<pair<int, int>> segs;
	for (int i = 0; i < mxn; ++i) {
		if (!mark[i]) {
			segs.push_back({len(tour), 0});
			dfs(i, 0);
			segs.back().second = len(tour);
			if (segs.back().second - segs.back().first == 0) {
				segs.pop_back();
			}
		}
	}
	string ans(mxn, 'b');
	for (auto &seg : segs) {
		int ind = seg.first;
		for (int i = seg.first; i < seg.second; ++i) {
			if (tour[i] > n) {
				ind = i;
				break;
			}
		}
		rotate(tour.begin() + seg.first, tour.begin() + ind, tour.begin() + seg.second);
		int x = 0;
		for (int i = seg.first; i < seg.second; ++i) {
			int e = tour[i];
			x ^= 1;
			if (e > n) {
				continue;
			}
			if (x == 1) {
				ans[e] = 'r';
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i];
	}
	return 0;
}

