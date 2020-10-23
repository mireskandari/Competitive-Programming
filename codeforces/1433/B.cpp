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
		int first = find(a.begin(), a.end(), 1) - a.begin();
		int last = a.rend() - find(a.rbegin(), a.rend(), 1);
		int cost = 0;
		for (int i = first; i < last; ++i) {
			if (a[i] == 0) {
				++cost;
			}
		}
		cout << cost << '\n';
	}
	return 0;
}
