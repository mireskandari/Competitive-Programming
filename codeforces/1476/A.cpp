#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, k;
		cin >> n >> k;
		k = ((n + k - 1) / k) * k;
		cout << (k + n - 1) / n << '\n';
	}
}

