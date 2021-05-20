#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

const int N = 1e3 + 10;

int dp[N][N][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N = 1e3 + 10;

	dp[0][0][1] = 1;
	dp[0][0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i + j == 0) {
				continue;
			}
			if (j == 0) {
				dp[i][j][0] = -dp[i - 1][j + 1][0] + 1;
				dp[i][j][1] = min(-dp[i][j][0] + 1, -dp[i - 1][j + 1][1] + 1);
			} else {
				int kir = -dp[i][j - 1][0] + 1;
				dp[i][j][0] = -dp[i][j - 1][0] + 1;
				if (i > 0) {
					kir = min(kir, -dp[i - 1][j + 1][0] + 1);
					dp[i][j][0] = min({dp[i][j][0], -kir, -dp[i - 1][j + 1][0] + 1});
				} else {
					dp[i][j][0] = min(dp[i][j][0], -kir);
				}
				kir = min(-dp[i][j - 1][1] + 1, -dp[i][j][0] + 1);
				dp[i][j][1] = min({-dp[i][j - 1][1] + 1, -dp[i][j][0] + 1});
				if (i > 0) {
					kir = min(kir, -dp[i - 1][j + 1][1] + 1);
					dp[i][j][1] = min({dp[i][j][1], -kir, -dp[i - 1][j + 1][1] + 1});
				} else {
					dp[i][j][1] = min(dp[i][j][1], -kir);
				}
			}
		}
	}
	
	auto print = [&](int i, int j, int k) {
		if (dp[i][j][k] == 0) {
			cout << "DRAW\n";
		}
		if (dp[i][j][k] > 0) {
			cout << "BOB\n";
		}
		if (dp[i][j][k] < 0) {
			cout << "ALICE\n";
		}
	};

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int f = 0, ss = 0;
		for (int i = 0; i < n / 2; ++i) {
			if (s[i] == s[n - i - 1] && s[i] == '0') {
				f++;
			}
			if (s[i] != s[n - i - 1]) {
				ss++;
			}
		}
		if (n % 2 == 1 && s[n / 2] == '0') {
			print(f, ss, 1);
		} else {
			print(f, ss, 0);
		}
	}
}