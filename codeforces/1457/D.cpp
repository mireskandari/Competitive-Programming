#include <bits/stdc++.h>
using namespace std;
template <typename T> int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int mn = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int r = 0;
		for (int j = i + 1; j < min(n, i + 100); ++j) {
			r ^= a[j];
			int l = 0;
			for (int k = i; k >= max(0, i - 100); --k) {
				l ^= a[k];
				if (l > r) {
					mn = min(mn, (j - (i + 1)) + (i - k));
				}
			}
		}
	}
	cout << (mn == INT_MAX ? -1 : mn);
	return 0;
}

