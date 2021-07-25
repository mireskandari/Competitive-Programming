#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		[]() {
			int n;
			cin >> n;
			vector<int> a(n);
			for (int i = 0; i < n; ++i) {
				cin >> a[i];
			}
			if (count(a.begin(), a.end(), 0) > 0) {
				cout << "YES\n";
				return;
			}
			for (int mask1 = 1; mask1 < (1 << n); ++mask1) {
				int kir = ~mask1 & ((1 << (__lg(mask1) + 1)) - 1);
				for (int mask2 = kir; mask2 > 0; --mask2 &= kir) {
					int sum1 = 0, sum2 = 0;
					for (int i = 0; i < n; ++i) {
						if (mask1 >> i & 1) {
							sum1 += a[i];
						}
						if (mask2 >> i & 1) {
							sum2 += a[i];
						}
					}
					if (sum1 == sum2 || sum1 == -sum2) {
						cout << "YES\n";
						return;
					}
				}
			}
			cout << "NO\n";
		}();
	}
}