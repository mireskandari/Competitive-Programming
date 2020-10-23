#include <bits/stdc++.h>
using namespace std;

const volatile auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define SHOW(a) #a << "=" << (a) << ", "

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		if (n == 1 || n == 2 || n == 4) {
			cout << -1 << '\n';
		} else if (n % 3 == 0) {
			cout << n / 3 << ' ' << 0 << ' ' << 0 << '\n';
		} else if (n % 3 == 1) {
			cout << n / 3 - 2 << ' ' << 0 << ' ' << 1 << '\n';
		} else if (n % 3 == 2) {
			cout << n / 3 - 1 << ' ' << 1 << ' ' << 0 << '\n';
		}
	}
	return 0;
}
