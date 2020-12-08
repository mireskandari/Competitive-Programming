#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> parent(n);
	iota(parent.begin(), parent.end(), 1);
	function<int(int, int)> pour = [&](int i, int x) {
		if (i == n) {
			return n;
		}
		if (b[i] + x < a[i]) {
			b[i] += x;
			return i;
		}
		parent[i] = pour(parent[i], x - a[i] + b[i]);
		b[i] = a[i];
		return parent[i];
	};
	int q;
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, x;
			cin >> i >> x;
			--i;
			pour(i, x);
		} else {
			int i;
			cin >> i;
			--i;
			cout << b[i] << '\n';
		}
	}
	return 0;
}

