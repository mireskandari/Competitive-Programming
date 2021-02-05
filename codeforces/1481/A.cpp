#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		int u = 0, d = 0, l = 0, r = 0;
		for (auto c : s) {
			if (c == 'L') {
				++l;
			}
			if (c == 'R') {
				++r;
			}
			if (c == 'U') {
				++u;
			}
			if (c == 'D') {
				++d;
			}
		}
		cout << ((-l <= x && x <= r) && (-d <= y && y <= u) ? "YES\n" : "NO\n");
	}
}

