#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int b1 = 0, b2 = 0, c1 = 0, c2 = 0;
		int ans = 0;
		for (int i = 0; i < len(s); ++i) {
			if (s[i] == '(') b1++;
			if (s[i] == ')' && b1 > 0) {
				ans++;
				b1--;
				b2++;
			}
			if (s[i] == '[') c1++;
			if (s[i] == ']' && c1 > 0) {
				ans++;
				c1--;
				c2++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

