#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 51;

int n, m;
string s[2];
int q;
bool can[2][26][N][N];
int dp[N][N];
set<string> vec[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> s[0] >> s[1];
	n = (int) s[0].size();
	m = (int) s[1].size();
	cin >> q;
	while (q--) {
		char c, tmp;
		cin >> c >> tmp;
		cin >> tmp;
		char one, two;
		cin >> one >> two;
		vec[c - 'a'].insert(string(1, one) + string(1, two));
	}
	
	for (int b = 0; b < 2; ++b) {
		for (int i = (int) s[b].size() - 1; i >= 0; --i) {
			can[b][s[b][i] - 'a'][i][i] = true;
			for (int c = 0; c < 26; ++c) {
				can[b][c][i][i + 1] = vec[c].count(string(1, s[b][i]) + string(1, s[b][i + 1]));
			}
			for (int j = i + 2; j < (int) s[b].size(); ++j) {
				for (int c = 0; c < 26; ++c) {
					for (int k = i; k < j; ++k) {
						for (auto &x : vec[c]) {
							can[b][c][i][j] |= can[b][x[0] - 'a'][i][k] && can[b][x[1] - 'a'][k + 1][j];
							/*if (can[b][c][i][j]) {
								cerr << b << ' ' << c << ' ' << i << ' ' << j << '\n';
							}*/
						}
					}
				}
			}
		}
	}
	
	memset(dp, 0x3f, sizeof(dp));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int c = 0; c < 26; ++c) {
				if (can[0][c][0][i] && can[1][c][0][j]) {
					dp[i][j] = 1;
				} else {
					for (int k = 1; k <= i; ++k) {
						for (int x = 1; x <= j; ++x) {
							if (can[0][c][k][i] && can[1][c][x][j]) {
								dp[i][j] = min(dp[i][j], dp[k - 1][x - 1] + 1);
							}
						}
					}
				}
			}
		}
	}
	
	cout << (dp[n - 1][m - 1] > 1e5 ? -1 : dp[n - 1][m - 1]);
}