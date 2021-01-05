#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> spf(1e6 + 10);
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		map<int, int> init_cnt;
		int max_before = INT_MIN;
		for (auto &i : a) {
			map<int, int> factor;
			while (spf[i] > 0) {
				factor[spf[i]]++;
				i /= spf[i];
			}
			int nw = 1;
			for (auto &f : factor) {
				nw *= (f.second & 1 ? f.first : 1);
			}
			init_cnt[nw]++;
			max_before = max(max_before, init_cnt[nw]);
		}
		map<int, int> after_cnt;
		int max_after = INT_MIN;
		for (auto &p : init_cnt) {
			if (p.second & 1) {
				after_cnt[p.first] = p.second;
				max_after = max(max_after, after_cnt[p.first]);
				continue;
			}
			after_cnt[1] += p.second;
			max_after = max(max_after, after_cnt[1]);
		}
		int q;
		cin >> q;
		while (q--) {
			long long w;
			cin >> w;
			if (w > 0) {
				cout << max_after << '\n';
			} else {
				cout << max_before << '\n';
			}
		}
	}
	return 0;
}

