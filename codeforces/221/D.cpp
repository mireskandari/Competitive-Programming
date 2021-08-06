#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 1e5 + 10, SQ = 350;

vector<int> pos[N];
int n, m, a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] <= n) {
			pos[a[i]].push_back(i);
		}
	}

	vector<int> kir;
	for (int i = 1; i <= n; ++i) {
		if (len(pos[i]) >= i) {
			kir.push_back(i);
		}
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		--u;
		int cnt = 0;
		for (auto &i : kir) {
			cnt += lower_bound(pos[i].begin(), pos[i].end(), v) - lower_bound(pos[i].begin(), pos[i].end(), u) == i;
		}
		cout << cnt << '\n';
	}
}