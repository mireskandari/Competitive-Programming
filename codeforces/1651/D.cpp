#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
#define X first
#define Y second
using P = pair<int, int>;

constexpr int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	set<P> st;
	vector<P> a(n);
	for (auto &p : a) {
		cin >> p.X >> p.Y;
	}
	
	vector<int> src;
	vector<P> all = a;
	vector<map<int, int>> mp(2e5 + 10);
	for (int i = 0; i < n; ++i) {
		auto p = all[i];
		mp[p.X][p.Y] = i;
	}

	for (auto &p : a) {
		for (int i = 0; i < 4; ++i) {
			int x = p.X + dx[i], y = p.Y + dy[i];
			if (!mp[x].count(y)) {
				src.push_back(all.size());
				mp[x][y] = all.size();
				all.push_back(P(x, y));
			}
		}
	}
	
	int m = (int) all.size();
	vector<int> dist(m, 1e9), par(m, -1);
	queue<int> q;
	for (auto &i : src) {
		par[i] = i;
		dist[i] = 0;
		q.push(i);
	}
	
	while (!q.empty()) {
		int x = all[q.front()].X, y = all[q.front()].Y;
		int ind = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0) {
				continue;
			}
			if (!mp[nx].count(ny)) {
				continue;
			}
			int ni = mp[nx][ny];
			if (dist[ni] > dist[ind] + 1) {
				dist[ni] = dist[ind] + 1;
				par[ni] = par[ind];
				q.push(ni);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << all[par[i]].X << ' ' << all[par[i]].Y << '\n';
	}
}