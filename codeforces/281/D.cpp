#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	vector<int> stk;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		while (!stk.empty() && a[stk.back()] < a[i]) {
			stk.pop_back();
		}
		if (!stk.empty()) {
			ans = max(ans, a[i] ^ a[stk.back()]);
		}
		stk.push_back(i);
	}
	stk.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!stk.empty() && a[stk.back()] < a[i]) {
			stk.pop_back();
		}
		if (!stk.empty()) {
			ans = max(ans, a[i] ^ a[stk.back()]);
		}
		stk.push_back(i);
	}
	cout << ans;
}