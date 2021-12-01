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
		long long h;
		cin >> n >> h;
		vector<long long> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		long long low = 1, high = 1e18;
		while (high - low > 0) {
			long long mid = low + (high - low) / 2;
			long long d = 0;
			for (int i = 0; i < n - 1; ++i) {
				d += min(a[i + 1] - a[i], mid);
			}
			d += mid;
			if (d >= h) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		cout << low << '\n';
	}
}