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
		if (n % 2 == 0) {
			cout << "YES\n";
		} else {
			bool found = false;
			for (int i = 0; i < n - 1; ++i) {
				if (a[i + 1] <= a[i]) {
					found = true;
				}
			}
			cout << (found ? "YES\n" : "NO\n");
		}
	}
}