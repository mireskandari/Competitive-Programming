#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> g(n);
	vector<pair<int, int>> intervals;
	for (int i = 0; i < n; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			pair<int, int> p;
			scanf("%d %d", &p.first, &p.second);
			for (int i = 0; i < (int)intervals.size(); ++i) {
				auto Check = [&](pair<int, int> f, pair<int, int> s, int ff, int ss) {
					if ((s.first < f.first && f.first < s.second) || (s.first < f.second && f.second < s.second)) {
						g[ff].push_back(ss);
					}
				};
				Check(intervals[i], p, i, (int)intervals.size());
				Check(p, intervals[i], (int)intervals.size(), i);
			}
			intervals.push_back(p);
		} else {
			int f, s;
			scanf("%d %d", &f, &s);
			--f;
			--s;
			vector<bool> mark(intervals.size());
			function<void(int)> Dfs = [&](int v) {
				mark[v] = true;
				for (auto& u : g[v]) {
					if (!mark[u]) {
						Dfs(u);
					}
				}
			};
			Dfs(f);
			if (!mark[s]) {
				puts("NO");
			} else {
				puts("YES");
			}
		}
	}
	return 0;
}

