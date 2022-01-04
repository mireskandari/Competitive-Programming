#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>> c(2 * n, vector<int>(2 * n));
		long long sum = 0;
		for (int i = 0; i < 2 * n; ++i) {
			for (int j = 0; j < 2 * n; ++j) {
				cin >> c[i][j];
				if (i >= n && j >= n) {
					sum += c[i][j];
				}
			}
		}
		int mn = INT_MAX;
		mn = min(c[2 * n - 1][0], mn);
		mn = min(c[0][2 * n - 1], mn);
		mn = min(c[0][n], mn);
		mn = min(c[2 * n - 1][n - 1], mn);
		mn = min(c[n - 1][2 * n - 1], mn);
		mn = min(c[n][0], mn);
		mn = min(c[n - 1][n], mn);
		mn = min(c[n][n - 1], mn);
		cout << sum + mn << '\n';
	}
}