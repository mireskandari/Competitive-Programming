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
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		long long ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans = max(ans, 1ll * a[i] * a[i + 1]);
		}
		cout << ans << '\n';
	}
}