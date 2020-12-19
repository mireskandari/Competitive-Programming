#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ud = (n + 1) / 2, we = n / 2;
	set<int> x, y;
	for (int i = 0; i <= ud; ++i) {
		y.insert(ud - i - i);
	}
	for (int i = 0; i <= we; ++i) {
		x.insert(we - i - i);
	}
	if (n % 2 == 0) {
		cout << 1ll * len(x) * len(y) << '\n';
		exit(0);
	}
	long long ans = 2ll * len(x) * len(y);
	for (auto &val : x) {
		if (y.count(val) == 1) {
			--ans;
		}
	}
	cout << ans;
	return 0;
}

