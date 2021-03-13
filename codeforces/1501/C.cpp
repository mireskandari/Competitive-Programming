#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<pair<int, int>> idx(n);
	for (int i = 0; i < n; ++i) {
		idx[i] = {a[i], i};
	}
	sort(idx.begin(), idx.end());
	int limit = sqrt(1e7);

	vector<vector<pair<int, int>>> fuckers(3e6);
	auto check_finish = [&](int diff) {
		for (auto &p : fuckers[diff]) {
			for (auto &q : fuckers[diff]) {
				set<int> hello{p.first, p.second, q.first, q.second};
				if (len(hello) == 4) {
					cout << "YES\n" << p.first + 1 << ' ' << q.second + 1 << ' ' << p.second + 1 << ' ' << q.first + 1 << '\n';
					exit(0);
				}
			}
		}
	};
	if (n <= limit) {
		for (int l = 1; l < n; ++l) {
			for (int i = 0; i < n - l; ++i) {
				int diff = idx[i + l].first - idx[i].first;
				fuckers[diff].push_back({idx[i].second, idx[i + l].second});
				if (len(fuckers[diff]) == 3) {
					check_finish(diff);
				}
			}
		}
	} else {
		int l = 1;
		for (int i = 0; i < n - l; ++i) {
			int diff = idx[i + l].first - idx[i].first;
			fuckers[diff].push_back({idx[i].second, idx[i + l].second});
			if (len(fuckers[diff]) == 3) {
				check_finish(diff);
			}
		}
	}

	for (int i = 0; i < len(fuckers); ++i) {
		check_finish(i);
	}
	cout << "NO";
}