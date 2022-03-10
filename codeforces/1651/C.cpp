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
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		vector<int> b(n);
		for (auto &i : b) {
			cin >> i;
		}
		int arr[2] = {}, arr2[2] = {};
		for (int i = 0; i < n; ++i) {
			if (abs(a[0] - b[i]) < abs(a[0] - b[arr[0]])) {
				arr[0] = i;
			}
			if (abs(a[n - 1] - b[i]) < abs(a[n - 1] - b[arr[1]])) {
				arr[1] = i;
			}
			if (abs(b[0] - a[i]) < abs(b[0] - a[arr2[0]])) {
				arr2[0] = i;
			}
			if (abs(b[n - 1] - a[i]) < abs(b[n - 1] - a[arr2[1]])) {
				arr2[1] = i;
			}
		}
		long long ans = LLONG_MAX;
		vector<int> tmp = {0, n - 1};
		for (int mask = 0; mask < 9; ++mask) {
			for (int mask1 = 0; mask1 < 9; ++mask1) {
				long long res = 0;
				set<pair<int, int>> st;
				//cerr << arr[0] << ' ' << arr[1] << ' ' << arr2[0] << ' ' << arr2[1] << '\n';
				st.insert({0, (mask % 3 <= 1 ? tmp[mask % 3] : arr[0])});
				st.insert({n - 1, (mask / 3 <= 1 ? tmp[mask / 3] : arr[1])});
				st.insert({(mask1 % 3 <= 1 ? tmp[mask1 % 3] : arr2[0]), 0});
				st.insert({(mask1 / 3 <= 1 ? tmp[mask1 / 3] : arr2[1]), n - 1});
				for (auto &e : st) {
					res += abs(a[e.first] - b[e.second]);
				}
				ans = min(res, ans);
			}
		}
		cout << ans << '\n';
	}
}