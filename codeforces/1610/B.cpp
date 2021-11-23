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
		auto check = [&](int x) {
			vector<int> b;
			for (int i = 0; i < n; ++i) {
				if (a[i] != x) {
					b.push_back(a[i]);
				}
			}
			int i = 0, j = (int) b.size() - 1;
			while (j - i >= 1 && b[i] == b[j]) {
				++i, --j;
			}
			return j - i < 1;
		};
		int i = 0, j = n - 1;
		bool ok = true;
		while (j - i >= 1) {
			if (a[i] == a[j]) {
				++i, --j;
			} else {
				ok = check(a[i]) || check(a[j]);
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}