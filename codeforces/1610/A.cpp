#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		if (n == 1 && m == 1) {
			cout << 0 << '\n';
			continue;

		}
		if (n == 1 || m == 1) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}