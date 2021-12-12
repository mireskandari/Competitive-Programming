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
		vector<int> stk;
		for (int i = n - 1; i >= 0; --i) {
			if (stk.empty() || a[i] > stk.back()) {
				stk.push_back(a[i]);
			}
		}
		cout << stk.size() - 1 << '\n';
	}
}