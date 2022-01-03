#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k > (n + 1) / 2) {
			cout << -1 << '\n';
			continue;
		}
		vector<string> a(n, string(n, '.'));
		for (int i = 0, c = 0; i < n && c < k; i += 2, c++) {
			a[i][i] = 'R';
		}
		for (int i = 0; i < n; ++i) {
			cout << a[i] << '\n';
		}	
	}
}