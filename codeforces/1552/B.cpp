#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 5e4 + 10;

int a[5][N];
int cnt[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		[]() {
			int n;
			cin >> n;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < 5; ++j) {
					cin >> a[j][i];
				}
			}
			if (n == 1) {
				cout << 1 << '\n';
				return;
			}
			vector<int> kir(n);
			iota(kir.begin(), kir.end(), 0);
			auto check = [&](int i, int j) {
				return ((int) (a[0][i] > a[0][j]) + (int) (a[1][i] > a[1][j]) + (int) (a[2][i] > a[2][j]) + (int) (a[3][i] > a[3][j]) + (int) (a[4][i] > a[4][j])) < 3;
			};
			while (len(kir) > 1) {
				int x = kir.back(), y = kir[len(kir) - 2];
				kir.pop_back();
				if (check(x, y)) {
					kir.pop_back();
					kir.push_back(x);
				}
			}
			for (int i = 0; i < n; ++i) {
				if (i != kir.back() && !check(kir.back(), i)) {
					cout << -1 << '\n';
					return;
				}
			}
			cout << kir[0] + 1 << '\n';
		}();
	}
}