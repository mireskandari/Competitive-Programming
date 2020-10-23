#include <bits/stdc++.h>
using namespace std;

const volatile auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define SHOW(a) #a << "=" << (a) << ", "

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
//		cerr << "FUCK\n";
		if ((int)set(a.begin(), a.end()).size() == 1) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<int> per(n);
		iota(per.begin(), per.end(), 0);
		vector<pair<int, int>> edge;
		int f = per.back();
		per.pop_back();
		while (!per.empty()) {
//			cerr << SHOW(per.size()) << SHOW(f) << '\n';
			vector<int> new_per;
			int new_f;
			for (auto &i : per) {
				if (a[i] == a[f]) {
					new_per.push_back(i);
				} else {
					new_f = i;
					edge.emplace_back(i, f);
				}
			}
			swap(per, new_per);
			swap(new_f, f);
		}
		for (auto& e : edge) {
			cout << e.first + 1 << ' ' << e.second + 1 << '\n';
		}
			
	}
	return 0;
}

