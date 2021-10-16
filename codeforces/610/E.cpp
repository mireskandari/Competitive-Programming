#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n, m, k;
string s;
int mat[10][10];
set<pair<pair<int, int>, int>> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k >> s;
	for (int i = 0; i < n - 1; ++i) {
		mat[s[i] - 'a'][s[i + 1] - 'a']++;
	}
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && s[i] == s[j]) {
			++j;
		}
		st.insert({{i, j - 1}, s[i] - 'a'});
	}

	while (m--) {
		int op;
		cin >> op;
		if (op == 2) {
			string p;
			cin >> p;
			vector<int> pos(k);
			for (int i = 0; i < k; ++i) {
				pos[p[i] - 'a'] = i;
			}
			int ans = 1;
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j < k; ++j) {
					ans += mat[i][j] * (pos[j] <= pos[i]);
				}
			}
			cout << ans << '\n';
		} else {
			int u, v;
			char c;
			cin >> u >> v >> c;
			--u, --v;
			auto l = prev(st.lower_bound({{u + 1, INT_MIN}, INT_MIN}));
			auto r = prev(st.lower_bound({{v + 1, INT_MIN}, INT_MIN}));
			
			vector<pair<pair<int, int>, int>> tmp;
			for (auto it = l; it != next(r); ++it) {
				tmp.push_back(*it);
			}
			
			int ll = tmp[0].first.first, rr = tmp.back().first.second, cc = tmp[0].second;
			if ((int) tmp.size() == 1) {
				mat[cc][cc] -= rr - ll;
			} else {
				mat[cc][cc] -= tmp[0].first.second - ll;
				for (int i = 1; i < (int) tmp.size(); ++i) {
					mat[cc][tmp[i].second]--;
					cc = tmp[i].second;
					mat[cc][cc] -= tmp[i].first.second - tmp[i].first.first;
				}
			}

			vector<pair<pair<int, int>, int>> tmp2;
			tmp2.push_back({{u, v}, c - 'a'});
			mat[c - 'a'][c - 'a'] += v - u;
			if (ll <= u - 1) {
				tmp2.push_back({{ll, u - 1}, tmp[0].second});
				mat[tmp[0].second][tmp[0].second] += u - 1- ll;
				mat[tmp[0].second][c - 'a']++;
			} else if (l != st.begin()) {
				mat[prev(l)->second][tmp[0].second]--;
				mat[prev(l)->second][c - 'a']++;
			}
			if (v + 1 <= rr) {
				tmp2.push_back({{v + 1, rr}, tmp.back().second});
				mat[tmp.back().second][tmp.back().second] += rr - v - 1;
				mat[c - 'a'][tmp.back().second]++;
			} else if (r != prev(st.end())) {
				mat[tmp.back().second][next(r)->second]--;
				mat[c - 'a'][next(r)->second]++;
			}
			
			for (auto &pr : tmp) {
				st.erase(pr);
			}
			for (auto &pr : tmp2) {
				st.insert(pr);
			}
		}
	}
}