#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 110;

vector<int> g[N];
bool mark[N];

void Dfs(int v) {
	mark[v] = true;
	for (auto& u : g[v]) {
		if (!mark[u]) {
			Dfs(u);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> points(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &points[i].first, &points[i].second);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (points[i].first == points[j].first || points[i].second == points[j].second) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!mark[i]) {
			Dfs(i);
			++cnt;
		}
	}
	printf("%d", cnt - 1);
	return 0;
}
