#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int p[1123], compo;

int root(int v) {
	return p[v] == v ? v : p[v] = root(p[v]);
}

bool unite(int v, int u) {
	v = root(v), u = root(u);
	p[v] = u;
	if (v != u) {
		--compo;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	iota(p, p + n, 0);
	compo = n;
	vector<pair<pair<int, int>, int>> es, eb;
	vector<pair<int, int>> ee(m);
	vector<int> added2;
	for (int i = 0; i < m; ++i) {
		int v, u;
		char c;
		cin >> v >> u >> c;
		--v;
		--u;
		if (c == 'S') {
			es.push_back({{v, u}, i});
		} else {
			eb.push_back({{v, u}, i});
			if (unite(v, u)) {
				added2.push_back(i);
			}
		}
		ee[i] = {v, u};
	}
	vector<int> added;
	for (auto &e : es) {
		if (unite(e.first.first, e.first.second)) {
			added.push_back(e.second);
		}
	}
	if (n % 2 == 0) {
		cout << -1;
		exit(0);
	}
	if (compo - 1 > (n - 1) / 2) {
		cout << -1;
		exit(0);
	}
	iota(p, p + n, 0);
	compo = n;
	for (auto &e : added) {
		unite(ee[e].first, ee[e].second);
	}
	for (auto &e : es) {
		if (compo - 1 == (n - 1) / 2) {
			break;
		}
		if (unite(e.first.first, e.first.second)) {
			added.push_back(e.second);
		}
	}
	if (compo - 1 != (n - 1) / 2) {
		cout << -1;
		exit(0);
	}
	added2.clear();
	for (auto &e : eb) {
		if (unite(e.first.first, e.first.second)) {
			added2.push_back(e.second);
		}
	}
	cout << n - 1 << '\n';
	for (auto &e : added) {
		cout << e + 1 << ' ';
	}
	for (auto &e : added2) {
		cout << e + 1 << ' ';
	}
	return 0;
}

