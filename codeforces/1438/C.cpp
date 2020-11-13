#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

const int N = 110;

int a[N][N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] % 2 != (i + j) % 2)
					a[i][j]++;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}

