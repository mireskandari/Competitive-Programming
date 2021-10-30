#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		if (x != y) {
			if (x > y) {
				long long n = x + y;
				assert(n % x == y % n);
				cout << n << '\n';
			} else {
				long long n = y - (y % x) / 2;
				assert(n % x == y % n);
				cout << n << '\n';
			}
		} else {
			cout << x << '\n';
		}
	}
}