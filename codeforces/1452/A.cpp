#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		if (abs(x - y) <= 0) {
			cout << x + y << '\n';
		} else {
			cout << abs(x - y) - 1 + x + y << '\n';
		}
	}
	return 0;
}

