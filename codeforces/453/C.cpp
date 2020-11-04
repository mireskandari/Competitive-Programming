#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
template <class T> inline int size(T& a) { return (int)a.size(); }

const int N = 1e5 + 10;

int n, m;
vector<int> g[N];
int x[N];
vector<int> ans;
bool mark[N];
int cnt1;

void Yes() {
	printf("%d\n", size(ans));
	for (auto i : ans)
		printf("%d ", i + 1);
	exit(0);
}

void Hi(int i) {
	x[i] = 1 - x[i];
	if (x[i] == 0)
		cnt1--;
	else
		cnt1++;
}

void Dfs(int v, int p) {
	if (cnt1 == 0)
		Yes();
	mark[v] = true;
	for (auto u : g[v]) {
		if (mark[u])
			continue;
		ans.push_back(u);
		Hi(u);
		Dfs(u, v);
		ans.push_back(v);
		Hi(v);
	}
	if (x[v] == 1) {
		if (p != -1) {
			ans.push_back(p);
			ans.push_back(v);
			Hi(v);
			Hi(p);
		}
	}
	if (cnt1 == 0)
		Yes();
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		if (x[i] == 1)
			cnt1++;
	}
	if (cnt1 == 0) 
		Yes();
	int v = find(x, x + n, 1) - x;
	ans.push_back(v);
	Hi(v);
	Dfs(v, -1);
	puts("-1");
	return 0;
}
