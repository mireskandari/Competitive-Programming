#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int x[2], y[2];
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		if (x[0] == x[1] || y[0] == y[1]) {
			cout << abs(x[0] - x[1]) + abs(y[0] - y[1]);
		} else {
			cout << abs(x[0] - x[1]) + abs(y[0] - y[1]) + 2;
		}
		cout << '\n';
	}
	return 0;
}

