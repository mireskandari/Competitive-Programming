#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		[]() {
			int n, m;
			cin >> n >> m;
			vector<int> a(n);
			for (auto &i : a) {
				cin >> i;
				--i;
			}
			vector<int> b(n);
			for (auto &i : b) {
				cin >> i;
				--i;
			}
			vector<int> c(m);
			for (auto &i : c) {
				cin >> i;
				--i;
			}
			
			vector<int> first_occ(n, n);
			for (int i = 0; i < n; ++i) {
				first_occ[b[i]] = min(first_occ[b[i]], i);
			}

			vector<vector<int>> needs(n);
			for (int i = 0; i < n; ++i) {
				if (a[i] != b[i]) {
					needs[b[i]].push_back(i);
				}
			}
			vector<int> cnt(n);
			for (int i = 0; i < m; ++i) {
				cnt[c[i]]++;
			}
			for (int i = 0; i < n; ++i) {
				if (len(needs[i]) > cnt[i]) {
					cout << "NO\n";
					return 0;
				}
			}
			
			vector<int> who(m, -1);
			for (int i = 0; i < m; ++i) {
				if (needs[c[i]].empty()) {
					continue;
				}
				who[i] = needs[c[i]].back();
				needs[c[i]].pop_back();
			}
			
			for (int i = m - 1; i >= 0; --i) {
				if (~who[i]) {
				} else {
					if (i == m - 1) {
						if (first_occ[c[i]] == n) {
							cout << "NO\n";
							return 0;
						}
						who[i] = first_occ[c[i]];
					} else {
						who[i] = who[i + 1];
					}
				}
			}

			cout << "YES\n";
			for (auto &i : who) {
				cout << i + 1 << ' ';
			}
			cout << '\n';
			return 0;
		}();
	}
}

