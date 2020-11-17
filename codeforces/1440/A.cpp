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
		long long n, c[2], h;
		cin >> n >> c[0] >> c[1] >> h;
		string s;
		cin >> s;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (c[0] - c[1] > h)
					ans += c[1] + h;
				else
					ans += c[0];
			} else {
				if (c[1] - c[0] > h)
					ans += c[0] + h;
				else
					ans += c[1];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

