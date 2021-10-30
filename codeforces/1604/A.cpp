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
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > (i + 1) + ans) {
				ans += a[i] - (i + 1) - ans;
			}
		}
		cout << ans << '\n';
	}
}