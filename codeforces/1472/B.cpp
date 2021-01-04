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
		int sum = 0;
		for (auto &i : a) {
			cin >> i;
			sum += i;
		}
		vector<bool> can(2 * n + 1);
		can[0] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = len(can) - 1; j >= 0; --j) {
				if (j - a[i] >= 0) {
					can[j] = can[j] || can[j - a[i]];
				}
			}
		}
		if (sum % 2 == 1) {
			cout << "NO\n";
			continue;
		}
		cout << (can[sum >> 1] ? "YES\n" : "NO\n");
	}
	return 0;
}

