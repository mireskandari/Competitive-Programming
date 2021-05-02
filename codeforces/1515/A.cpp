#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		if (accumulate(a.begin(), a.end(), 0) == x) {
			cout << "NO\n";
			continue;
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += a[i];
			if (sum == x) {
				swap(a[i], a[i + 1]);
				break;
			}
		}
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}

