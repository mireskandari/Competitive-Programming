#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	cout << fixed << setprecision(15);
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		vector<pair<int, double>> b(m);
		for (auto& i : b) {
			cin >> i.first >> i.second;
			--i.first;
		}
		vector<bool> is(n + 1);
		is.back() = true;
		for (int i = n - 1; i >= 0; --i) {
			is[i] = is[i + 1] && a[i] == i + 1;
		}
		double prob = 0;
		double pref = 1;
		if (is[0]) {
			cout << 1.0 << '\n';
			continue;
		}
		for (auto& i : b) {
			if (!is[i.first + 1]) {
				continue;
			}
			prob += pref * i.second;
			pref *= 1.0 - i.second;
		}
		cout << prob << '\n';
	}
	return 0;
}

