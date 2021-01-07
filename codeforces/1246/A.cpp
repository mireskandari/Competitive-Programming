#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, p;
	cin >> n >> p;
	for (int i = 0; i < 50; ++i) {
		if (__builtin_popcount(1ll * n - p * i) <= i && i <= 1ll * n - p * i) {
			cout << i;
			exit(0);
		}
	}
	cout << -1;
	return 0;
}

