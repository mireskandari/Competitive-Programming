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
			--i;
		}
		set<int> left;
		for (int i = 0; i < n; ++i) {
			left.insert(i);
		}
		vector<int> perm;
		int last = -1;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] != *left.rbegin()) {
				continue;
			}
			for (int j = i; j < n; ++j) {
				if (a[j] == last) {
					break;
				}
				perm.push_back(a[j]);
				left.erase(a[j]);
			}
			last = a[i];
		}
		for (auto &i : perm) {
			cout << i + 1 << ' ';
		}
		cout << '\n';
	}

}

