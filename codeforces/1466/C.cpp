#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int n = len(s);
		vector<bool> change(n);
		for (int i = 0; i < n; ++i) {
			if (change[i]) {
				continue;
			}
			if (i < n - 1 && s[i] == s[i + 1]) {
				change[i + 1] = true;
			}
			if (i < n - 2 && s[i] == s[i + 2]) {
				change[i + 2] = true;
			}
		}
		cout << count(change.begin(), change.end(), true) << '\n';
	}
	return 0;
}

