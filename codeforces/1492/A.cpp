#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;

	while (tc--) {
		long long p, a, b, c;
		cin >> p >> a >> b >> c;
		cout << min({(a - p % a) % a, (b - p % b) % b, (c - p % c) % c}) << '\n';
	}
}