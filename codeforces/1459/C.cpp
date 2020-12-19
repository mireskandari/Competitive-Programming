#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<long long> a(n), b(m);
	for (auto &i : a) {
		cin >> i;
	}
	for (auto &i : b) {
		cin >> i;
	}
	if (n == 1) {
		for (auto &i : b) {
			cout << a[0] + i << ' ';
		}
		exit(0);
	}
	long long g = abs(a[1] - a[0]);
	for (int i = 2; i < n; ++i) {
		g = __gcd(g, abs(a[i] - a[i - 1]));
	}
	for (auto &i : b) {
		cout << __gcd(g, a[0] + i) << ' ';
	}
	return 0;
}

