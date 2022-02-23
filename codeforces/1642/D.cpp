#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

vector<int> sz;

vector<pair<int, int>> solve(vector<int> a) {
	if (a.empty()) {
		return {};
	}
	vector<pair<int, int>> ans;
	vector<int> tmp;
	for (int i = 1; i < (int) a.size(); ++i) {
		if (a[i] == a[0]) {
			for (int j = 1; j < i; ++j) {
				ans.push_back({i + j, a[j]});
				tmp.push_back(a[j]);
			}
			sz.push_back(2 * i);
			reverse(tmp.begin(), tmp.end());
			for (int j = i + 1; j < (int) a.size(); ++j) {
				tmp.push_back(a[j]);
			}
			auto ret = solve(tmp);
			for (auto &x : ret) {
				ans.push_back({x.first + 2 * i, x.second});
			}
			return ans;
		}
	}
	assert(false);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		sz.clear();
		vector<int> a(n);
		map<int, bool> parity;
		for (auto &i : a) {
			cin >> i;
			parity[i] ^= 1;
		}
		bool bad = false;
		for (auto &x : parity) {
			if (x.second) {
				cout << -1 << '\n';
				bad = true;
				break;
			}
		}
		if (bad) {
			continue;
		}
		auto ans = solve(a);
		cout << ans.size() << '\n';
		for (auto &q : ans) {
			cout << q.first << ' ' << q.second << '\n';
		}
		cout << sz.size() << '\n';
		for (auto &s : sz) {
			cout << s << ' ';
		}
		cout << "\n";
	}
}