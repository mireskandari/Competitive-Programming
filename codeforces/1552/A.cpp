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
		cin >> s;
		t = s;
		sort(t.begin(), t.end());
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (t[i] != s[i]) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}