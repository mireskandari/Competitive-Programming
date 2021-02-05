#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		[]() {
			int n, k;
			cin >> n >> k;
			vector<int> h(n);
			for (auto &i : h) {
				cin >> i;
			}
			while (true) {
				int j = 0;
				while (j < n - 1 && h[j] >= h[j + 1]) {
					++j;
				}
				if (j == n - 1) {
					cout << -1 << '\n';
					return 0;
				}
				int cnt = min(j ? h[j - 1] + 1 - h[j] : INT_MAX, h[j + 1] - h[j]);
				h[j] += cnt;
				k -= cnt;
				if (k <= 0) {
					cout << j + 1 << '\n';
					return 0;
				}
			}
		}();
	}
}

