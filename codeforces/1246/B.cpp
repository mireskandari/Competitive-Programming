#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	map<vector<int>, int> mp;
	vector<int> spf(1e5 + 10);
	for (int i = 2; i < len(spf); ++i) {
		if (spf[i] == 0) {
			spf[i] = i;
			for (int j = 2 * i; j < len(spf); j += i) {
				if (spf[j] == 0) {
					spf[j] = i;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		map<int, int> factor;
		int j = a[i];
		while (spf[j] > 1) {
			factor[spf[j]]++;
			j /= spf[j];
		}
		vector<int> guys, inv;
		for (auto &f : factor) {
			if (f.second % k == 0) {
				continue;
			}
			int ff = f.first * 100;
			int s = f.second % k;
			guys.push_back(ff + s);
			inv.push_back(ff + (k - s));
		}
		ans += mp[inv];
		mp[guys]++;
	}
	cout << ans;
	return 0;
}

