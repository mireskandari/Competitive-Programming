#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int N = 1e3 + 10;

char a[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		[]() {
			int n, m;
			cin >> n >> m;
			
			for (int i = 0; i < n; ++i) {
				cin >> a[i];
			}

			if (m == 1) {
				cout << "YES\n";
				cout << 1 << ' ' << 2 << '\n';
				return 0;
			}

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < i; ++j) {
					if (a[i][j] == a[j][i]) {
						cout << "YES\n";
						for (int x = 0; x < (m + 1) / 2; ++x) {
							cout << i + 1 << ' ' << j + 1 << ' ';
						}
						if (m % 2 == 0) {
							cout << i + 1 << ' ';
						}
						cout << '\n';
						return 0;
					}
				}
			}
			
			if (m & 1) {
				cout << "YES\n";
				for (int x = 0; x < (m + 1) / 2; ++x) {
					cout << 1 << ' ' << 2 << ' ';
				}
				return 0;
			}
			
			if (n == 2) {
				cout << "NO\n";
				return 0;
			}

			vector<int> kir{0, 1, 2};
			do {
				int x = kir[0], y = kir[1], z = kir[2];
				if (m % 4 == 2) {
					if (a[x][y] == a[y][z]) {
						cout << "YES\n";
						cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << ' ';
						for (int i = 0; i < (m / 4); ++i) {
							cout << y + 1 << ' ' << x + 1 << ' ' << y + 1 << ' ' << z + 1 << ' ';
						}
						cout << '\n';
						return 0;
					}
				} else {
					if (a[x][y] == a[y][z]) {
						cout << "YES\n";
						cout << y + 1 << ' ';
						for (int i = 0; i < (m / 4); ++i) {
							cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << ' ' << y + 1 << ' ';
						}
						cout << '\n';
						return 0;
					}
				}
			} while (next_permutation(kir.begin(), kir.end()));
			
			return 0;
		}();
	}
}

