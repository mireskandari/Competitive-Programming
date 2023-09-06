#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG: "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		vector<int> b = a;
		sort(b.begin(), b.end());
		int mex = n;
		for (int i = 0; i < n; ++i) {
			if (b[i] != i) {
				mex = i;
				break;
			}
		}
		a.push_back(mex);
		for (int i = 0; i < n - 1; ++i) {
			a.push_back(a[i]);
		}
		int s = (n + 1 - (k % (n + 1))) % (n + 1);
		for (int i = 0; i < n; ++i) {
			cout << a[s + i] << ' ';
		}
		cout << '\n';
	}
}