#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int h, w, n;
		cin >> h >> w >> n;
		int two = 0;
		while (h % 2 == 0) {
			two++;
			h >>= 1;
		}
		while (w % 2 == 0) {
			two++;
			w >>= 1;
		}
		cout << ((1ll << two) >= n ? "YES" : "NO") << '\n';
	}
	return 0;
}

