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
		long long num = 1;
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			ans.push_back(num);
			num *= 3;
			if (num > 1000000000) {
				break;
			}
		}
		if ((int) ans.size() < n) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (auto &x : ans) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}
}