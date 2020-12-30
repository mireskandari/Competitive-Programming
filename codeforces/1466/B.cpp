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
		set<int> vals;
		for (int i = n - 1; i >= 0; --i) {
			if (vals.count(a[i] + 1) == 0) {
				vals.insert(a[i] + 1);
			} else {
				vals.insert(a[i]);
			}
		}
		cout << len(vals) << '\n';
	}
	return 0;
}

