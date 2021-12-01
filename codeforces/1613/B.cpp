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
		sort(a.begin(), a.end());
		int c = 0;
		for (int i = 1; c < n / 2; ++i) {
			cout << a[i] << ' ' << a[0] << '\n';
			++c;
		}
	}
}