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
		int n;
		cin >> n;
		cout << n << '\n';
		for (int i = 1; i <= n; ++i)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}

