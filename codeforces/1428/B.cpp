#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		{
			int i = 0;
			while (i < n && (s[i] == '-' || s[i] == '>')) {
				++i;
			}
			if (i == n) {
				cout << n << '\n';
				continue;
			}
			i = n - 1;
			while (i >= 0 && (s[i] == '-' || s[i] == '<')) {
				--i;
			}
			if (i == -1) {
				cout << n << '\n';
				continue;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int prv = (i - 1 + n) % n;
			if (s[prv] == '-' || s[i] == '-') {
				++cnt;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}

