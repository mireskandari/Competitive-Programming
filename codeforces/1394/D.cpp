#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n;
long long ans;
int in[N], out[N];
vector<int> g[N];
long long up[N], down[N], all[N];
bool mark[N];
int t[N], h[N];

void dfs(int v) {
	mark[v] = true;
	vector<long long> vec;
	long long sum = 0;
	for (auto &u : g[v]) {
		if (!mark[u]) {
			dfs(u);
			vec.push_back(up[u] - down[u]);
			sum += down[u];
		}
	}
	sort(vec.begin(), vec.end(), greater<long long>());
	for (int i = 0; i <= (int) vec.size(); ++i) {
		if (i) {
			sum += vec[i - 1];
		}
		long long indeg = in[v] + i;
		long long outdeg = out[v] + ((int) vec.size()) - i;
		up[v] = max(up[v], min(indeg, outdeg + 1) * t[v] + sum);
		down[v] = max(down[v], min(indeg + 1, outdeg) * t[v] + sum);
		all[v] = max(all[v], min(indeg, outdeg) * t[v] + sum);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (h[u] == h[v]) {
			g[u].push_back(v);
			g[v].push_back(u);
		} else {
			if (h[u] > h[v]) {
				swap(u, v);
			}
			out[u]++;
			in[v]++;
		}
		ans += t[u] + t[v];
	}

	for (int i = 0; i < n; ++i) {
		if (!mark[i]) {
			dfs(i);
			ans -= all[i];
		}
	}

	cout << ans;
}