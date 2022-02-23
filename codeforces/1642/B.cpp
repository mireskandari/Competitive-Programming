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
		set<int> s(a.begin(), a.end());
		int sz = (int) s.size();
		for (int i = 1; i <= n; ++i) {
			if (i <= sz) {
				cout << sz << ' ';
			} else {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}