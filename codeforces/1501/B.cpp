#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> guys(n, -1);
		for (int i = 0; i < n; ++i) {
			if (!a[i]) {
				continue;
			}
			int to = max((i + 1) - a[i], 0);
			guys[to] = max(guys[to], i);
		}
		set<int> open;
		vector<bool> cool(n);
		for (int i = 0; i < n; ++i) {
			if (guys[i] >= i) {
				open.insert(guys[i]);
			}
			cool[i] = !open.empty() && *open.rbegin() >= i;
		}
		for (int i = 0; i < n; ++i) {
			cout << (cool[i] ? 1 : 0) << ' ';
		}
		cout << '\n';
	}
}