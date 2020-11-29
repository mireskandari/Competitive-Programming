#include <bits/stdc++.h>
using namespace std;
template <typename T> int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, m, r, c;
		// fuck misreading
		cin >> n >> m >> r >> c;
		auto dist = [&](long long x, long long y) {
			return abs(x - r) + abs(c - y);
		};
		cout << max({dist(1, m), dist(n, m), dist(1, 1), dist(n, 1)}) << '\n';
	}
	return 0;
}

