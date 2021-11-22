#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		[]() {
			int x, y;
			cin >> x >> y;
			for (int i = 0; i <= x; ++i) {
				for (int j = 0; j <= y; ++j) {
					if (x - i + y - j == i + j) {
						cout << i << ' ' << j << '\n';
						return;
					}
				}
			}
			cout << -1 << ' ' << -1 << '\n';
			return;
		}();
	}
}