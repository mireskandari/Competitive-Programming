#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int mxn = 1e6 + 10;

vector<pair<int, int>> g[mxn];
bool emark[mxn];
vector<int> tour;

void dfs(int v) {
	while (!g[v].empty()) {
		int u = g[v].back().first, i = g[v].back().second;
		g[v].pop_back();
		if (emark[i]) {
			continue;
		}
		emark[i] = true;
		dfs(u);
	}
	tour.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	map<string, int> idx;
	vector<string> mp(mxn);
	vector<int> indeg(mxn), outdeg(mxn);

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		string ff = s.substr(0, 2), ss = s.substr(1, 2);
		if (!idx.count(ff)) {
			int j = len(idx);
			idx[ff] = j;
			mp[j] = ff;
		}
		if (!idx.count(ss)) {
			int j = len(idx);
			idx[ss] = j;
			mp[j] = ss;
		}
		g[idx[ff]].push_back({idx[ss], i});
		outdeg[idx[ff]]++;
		indeg[idx[ss]]++;
	}
	
	vector<int> odd;
	for (int i = 0; i < mxn; ++i) {
		if (abs(indeg[i] - outdeg[i]) > 1) {
			cout << "NO";
			exit(0);
		}
		if (indeg[i] != outdeg[i]) {
			odd.push_back(i);
		}
	}
	if (len(odd) > 2) {
		cout << "NO";
		exit(0);
	}
	if (odd.empty()) {
		odd.push_back(idx.begin()->second);
	}

	dfs(outdeg[odd.back()] > indeg[odd.back()] ? odd.back() : odd[0]);
	reverse(tour.begin(), tour.end());
	
	if (len(tour) != n + 1) {
		cout << "NO";
		exit(0);
	}

	cout << "YES\n" << mp[tour.front()];
	for (int i = 1; i < len(tour); ++i) {
		cout << mp[tour[i]][1];
	}
	return 0;
}

