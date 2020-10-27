#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 2010;

vector<int> g[N];
int depth[N];
bool mark[N];

void Dfs(int v) {
	mark[v] = true;
	for (auto& u : g[v]) {
		if (!mark[u]) {
			depth[u] = depth[v] + 1;
			Dfs(u);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> start;
	for (int i = 0; i < n; ++i) {
		int parent;
		scanf("%d", &parent);
		if (parent != -1) {
			g[--parent].push_back(i);
		} else {
			start.push_back(i);
		}
	}
	for (auto& v : start) {
		depth[v] = 1;
		Dfs(v);
	}
	printf("%d", *max_element(depth, depth + n));
	return 0;
}
