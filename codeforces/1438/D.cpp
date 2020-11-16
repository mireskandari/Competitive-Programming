#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr int N = 1e5 + 10;

int a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int xorall = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		xorall ^= a[i];
	}
	if (n % 2 == 0 && xorall > 0) {
		cout << "NO";
		exit(0);
	}
	vector<tuple<int, int, int>> ans;
	for (int i = 0; i < n - 2; i += 2) {
		ans.push_back(make_tuple(i + 1, i + 2, i + 3));
	}
	for (int i = n & 1 ? n - 3 : n - 2; i >= 2; i -= 2) {
		ans.push_back(make_tuple(i + 1, i, i - 1));
	}
	cout << "YES\n";
	cout << len(ans) << '\n';
	for (auto& t : ans) {
		cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
	}
	return 0;
}

