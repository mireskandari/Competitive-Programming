#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n, m;
vector<int> g[N];
bool mark[N];
int dep[N];
int par[N];
set<pair<int, int>> up[N];
vector<int> ans[3];

void found(pair<int, int> v, pair<int, int> u) {
	if (dep[v.first] > dep[v.second]) {
		swap(v.first, v.second);
	}
	if (dep[u.first] > dep[u.second]) {
		swap(u.first, u.second);
	}
	vector<int> vec = {v.first, v.second, u.first, u.second};
	sort(vec.begin(), vec.end(), [&](int i, int j) {
		return dep[i] < dep[j];
	});
	int x = vec[3];
	{
		while (dep[x] > dep[vec[2]]) {
			x = par[x];
		}
		int y = vec[2];
		while (x != y) {
			x = par[x];
			y = par[y];
		}
	}
	ans[0].push_back(x);
	int p = x;
	while (p != vec[1]) {
		ans[0].push_back(par[p]);
		p = par[p];
	}
	
	//cerr << "DID\n";
	ans[1].push_back(v.second);
	p = v.second;
	while (p != x) {
		ans[1].push_back(par[p]);
		p = par[p];
	}
	reverse(ans[1].begin(), ans[1].end());
	ans[1].push_back(v.first);
	vector<int> tmp;
	p = vec[1];
	while (p != v.first) {
		tmp.push_back(p);
		p = par[p];
	}
	while (!tmp.empty()) {
		ans[1].push_back(tmp.back());
		tmp.pop_back();
	}
	//cerr << "DID\n";

	ans[2].push_back(u.second);
	p = u.second;
	while (p != x) {
		ans[2].push_back(par[p]);
		p = par[p];
	}
	reverse(ans[2].begin(), ans[2].end());
	ans[2].push_back(u.first);
	p = vec[1];
	while (p != u.first) {
		tmp.push_back(p);
		p = par[p];
	}
	while (!tmp.empty()) {
		ans[2].push_back(tmp.back());
		tmp.pop_back();
	}

	//cerr << "DID\n";

	cout << "YES\n";
	for (int i = 0; i < 3; ++i) {
		cout << ans[i].size() << ' ';
		for (auto &vert : ans[i]) {
			cout << vert + 1 << ' ';
		}
		cout << '\n';
	}
	exit(0);
}

void dfs(int v, int p) {
	mark[v] = true;
	par[v] = p;
	for (auto &u : g[v]) {
		if (!mark[u]) {
			dep[u] = dep[v] + 1;
			dfs(u, v);
			if (!up[u].empty()) {
				up[v].insert(*up[u].begin());
			}
		}
	}
	for (auto &u : g[v]) {
		if (dep[u] > dep[v]) {
			up[v].erase(make_pair(v, u));
		} else if (u != p) {
			up[v].insert(make_pair(u, v));
		}
	}
	if ((int) up[v].size() <= 1) {
		return;
	}
	found(*up[v].begin(), *next(up[v].begin()));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(par, -1, sizeof(par));
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}

	for (int i = 0; i < n; ++i) {
		if (!mark[i]) {
			dfs(i, -1);
		}
	}

	cout << "NO";
}