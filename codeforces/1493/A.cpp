#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n, k;
		cin >> n >> k;
		int cnt = n - k + k / 2;
		vector<int> a;
		for (int i = n; i > k; --i) {
			a.push_back(i);
		}
		for (int i = 1; i < k; ++i) {
			if (k - i <= i) {
				a.push_back(i);
			}
		}
		cout << cnt << '\n';
		for (auto &i : a) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}
 
