#include <bits/stdc++.h>
using namespace std;

const volatile auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define SHOW(a) #a << "=" << (a) << ", "

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int n = (int)s.size();
		cout << (int)(s[0] - '1') * 10 + vector<int>{10, 1, 3, 6}[n % 4] << '\n';
	}
	return 0;
}
