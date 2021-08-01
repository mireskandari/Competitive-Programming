#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> in(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		if (v < u) {
			in[v]++;
		} else {
			in[u]++;
		}
	}
	
	int ans = count(in.begin(), in.end(), 0);
	int q;
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			int s = min(u, v);
			if (in[s] == 0) {
				ans--;
			}
			in[s]++;
		} else if (op == 2) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			int s = min(u, v);
			if (in[s] == 1) {
				ans++;
			}
			in[s]--;
		} else {
			cout << ans << '\n';
		}
	}
}