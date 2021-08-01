#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (t[i] == '0') {
				continue;
			}
			if (i > 0 && s[i - 1] == '1') {
				ans++;
				s[i - 1] = '2';
				continue;
			}
			if (s[i] == '0') {
				ans++;
				s[i] = '2';
				continue;
			}
			if (i < n - 1 && s[i + 1] == '1') {
				ans++;
				s[i + 1] = '2';
			}

		}
		cout << ans << '\n';
	}
}