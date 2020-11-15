#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr int N = 11;

int a[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> manfi;
		vector<int> mosbat;
		long long sum1 = 0;
		long long sum2 = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
				if (a[i][j] < 0) {
					manfi.push_back(a[i][j]);
					sum1 += a[i][j];
				} else {
					mosbat.push_back(a[i][j]);
					sum2 += a[i][j];
				}
			}
		}
		sort(manfi.begin(), manfi.end());
		sort(mosbat.begin(), mosbat.end());
		if (len(manfi) % 2 == 0) {
			cout << -sum1 + sum2 << '\n';
		} else {
			long long ans = -sum1 + sum2 + 2 * manfi.back();
			if (!mosbat.empty()) 
				ans = max(ans, -sum1 + sum2 - 2 * mosbat.front());
			cout << ans << '\n';
		}

	}
	return 0;
}

