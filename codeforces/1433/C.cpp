#include <bits/stdc++.h>
using namespace std;

const volatile auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define SHOW(a) #a << "=" << (a) << ", "

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if ((int)set(a.begin(), a.end()).size() == 1) {
			cout << "-1\n";
		} else {
			int mx = *max_element(a.begin(), a.end());
			for (int i = 0; i < n; ++i) {
				if (i > 0 && a[i] == mx && a[i] > a[i - 1]) {
					cout << i + 1 << '\n';
					break;
				}
				if (i < n - 1 && a[i] == mx && a[i] > a[i + 1]) {
					cout << i + 1 << '\n';
					break;
				}
			}
		}
	}
	return 0;
}
