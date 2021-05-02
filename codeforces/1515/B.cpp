#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		auto is_sq = [](int x) {
			if (1ll * ceil(sqrt(x)) * ceil(sqrt(x)) == x || 1ll * floor(sqrt(x)) * floor(sqrt(x)) == x) {
				return true;
			}
			return false;
		};
		cout << (n & 1 ? "NO" : (is_sq(n / 2) ? "YES" : (n % 4 == 0 && is_sq(n / 4) ? "YES" : "NO"))) << '\n';
	}
}
