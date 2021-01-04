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
		sort(a.begin(), a.end());
		long long f = 0, s = 0;
		for (int i = n - 1, x = 0; i >= 0; --i, x ^= 1) {
			if (x) {
				if (a[i] & 1) {
					s += a[i];
				}
			} else {
				if (!(a[i] & 1)) {
					f += a[i];
				}
			}
		}
		cout << (f > s ? "Alice" : (f < s ? "Bob" : "Tie")) << '\n';
	}
	return 0;
}

