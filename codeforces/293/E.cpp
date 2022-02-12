#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int fen[N];

void update(int i, int x) {
	for (++i; i < N; i += i & -i) {
		fen[i] += x;
	}
}

int query(int i) {
	int res = 0;
	for (++i; i > 0; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

int n, cl, cw;
vector<pair<int, int>> g[N];
bool used[N];
int sz[N];

void prep(int v, int p) {
	sz[v] = 1;
	for (auto &e : g[v]) {
		if (e.first != p && !used[e.first]) {
			prep(e.first, v);
			sz[v] += sz[e.first];
		}
	}
}

int centroid(int v, int p, int m) {
	bool good = true;

	for (auto &e : g[v]) {
		if (e.first != p && !used[e.first]) {
			int ret = centroid(e.first, v, m);
			if (ret != -1) {
				return ret;
			}
			if (sz[e.first] > m / 2) {
				good = false;
			}
		}
	}
	
	if (m - sz[v] > m / 2) {
		good = false;
	}
	
	return good ? v : -1;
}

pair<int, int> dep[N];
vector<pair<int, int>> stuff[N];

void dfs(int v, int p, int root) {
	//cerr << "DFS: " << v << '\n';
	stuff[root].push_back(dep[v]);
	for (auto &e : g[v]) {
		if (e.first != p && !used[e.first]) {
			dep[e.first] = {dep[v].first + e.second, dep[v].second + 1};
			dfs(e.first, v, root);
		}
	}
}

long long count(int v) {
	auto &vec = stuff[v];
	sort(vec.begin(), vec.end());
	
	vector<vector<int>> que(vec.size());
	for (int i = 0; i < (int) vec.size(); ++i) {
		auto &x = vec[i];
		auto tmp = upper_bound(vec.begin(), vec.end(), make_pair(cw - x.first, INT_MAX));
		if (tmp == vec.begin()) {
			continue;
		}
		if (min((int) (tmp - vec.begin()), i) - 1 < 0) {
			continue;
		}
		que[min((int) (tmp - vec.begin() - 1), i - 1)].push_back(cl - x.second);
	}
	
	long long ret = 0;

	for (int i = 0; i < (int) vec.size(); ++i) {
		update(vec[i].second, +1);
		for (auto &q : que[i]) {
			if (q >= 0) {
				ret += query(q);
			}
		}
	}
	for (auto &x : vec) {
		update(x.second, -1);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> cl >> cw;
	for (int i = 1; i < n; ++i) {
		int p, w;
		cin >> p >> w;
		--p;
		g[i].push_back({p, w});
		g[p].push_back({i, w});
	}

	
	queue<int> q;
	q.push(0);
	
	long long ans = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		//cerr << v << '\n';
		prep(v, -1);
		//cerr << sz[v] << '\n';
		int c = centroid(v, -1, sz[v]);
		//cerr << c << '\n';
		vector<pair<int, int>>().swap(stuff[c]);
		//cerr << "FUCK\n";
		long long shit = 0;

		for (auto &e : g[c]) {
			if (!used[e.first]) {
				dep[e.first] = {e.second, 1};
				vector<pair<int, int>>().swap(stuff[e.first]);
				
				dfs(e.first, c, e.first);
				shit -= count(e.first);
				
				for (auto &x : stuff[e.first]) {
					stuff[c].push_back(x);
				}

				q.push(e.first);
			}
		}
		shit += count(c);
		for (auto &x : stuff[c]) {
			if (x.first <= cw && x.second <= cl) {
				shit++;
			}
		}
		ans += shit;
		//cerr << "     " << shit << '\n';

		used[c] = true;
	}

	cout << ans;
}