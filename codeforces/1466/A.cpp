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
		for (auto &i : a) {
			cin >> i;
		}
		set<int> area;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				area.insert(abs(a[i] - a[j]));
			}
		}
		cout << len(area) << '\n';
	}
	return 0;
}

