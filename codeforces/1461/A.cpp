#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cout << (char) ('a' + (i % 3));
		}
		cout << '\n';
	}
	return 0;
}

