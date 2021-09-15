#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10, SQ = 350;

int n, m, q;
long long a[N];
vector<int> s[N], heavy;
int idx[N];
long long add[N], add2[N];
int inter[N / SQ][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int heavy_cnt = 0;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		if (k >= SQ) {
			idx[i] = heavy_cnt++;
			heavy.push_back(i);
		} else {
			idx[i] = -1;
		}
		s[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> s[i][j];
			--s[i][j];
			add[i] += a[s[i][j]];
		}
	}
	
	for (auto &i : heavy) {
		vector<bool> temp(n);
		for (auto &j : s[i]) {
			temp[j] = true;
		}
		for (int j = 0; j < n; ++j) {
			for (auto &x : s[j]) {
				if (temp[x]) {
					inter[idx[i]][j]++;
				}
			}
		}
	}

	while (q--) {
		char op;
		cin >> op;
		if (op == '?') {
			int i;
			cin >> i;
			--i;
			if (~idx[i]) {
				long long ans = add[i];
				for (auto &j : heavy) {
					if (j != i) {
						ans += 1ll * add2[j] * inter[idx[i]][j];
					}
				}
				cout << ans << '\n';
			} else {
				long long ans = 0;
				for (auto &j : s[i]) {
					ans += a[j];
				}
				for (auto &j : heavy) {
					ans += 1ll * add2[j] * inter[idx[j]][i];
				}
				cout << ans << '\n';
			}
		} else {
			int i, x;
			cin >> i >> x;
			--i;
			if (~idx[i]) {
				add[i] += 1ll * ((int) s[i].size()) * x;
				add2[i] += x;
			} else {
				for (auto &j : s[i]) {
					a[j] += x;
				}
				for (auto &j : heavy) {
					add[j] += 1ll * inter[idx[j]][i] * x;
				}
			}
		}
	}
}

