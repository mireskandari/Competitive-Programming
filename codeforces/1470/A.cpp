#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> k(n);
		vector<int> c(m);
		for (auto &i : k) {
			cin >> i;
			--i;
		}
		for (auto &i : c) {
			cin >> i;
		}
		
		sort(k.rbegin(), k.rend());
		int ptr = 0;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (ptr > k[i] || c[k[i]] == c[ptr]) {
				ans += c[k[i]];
			} else {
				ans += c[ptr++];
			}
		}
		
		cout << ans << '\n';
	}
	return 0;
}

