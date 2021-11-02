#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 160, INF = 1e9;

int n, a[N], dp1[N][N], dp3[N][N][N];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < 0) {
			a[i] = -INF;
		}
	}
	cin >> s;
	
	fill(&dp3[0][0][0], &dp3[N - 1][N - 1][N - 1] + 1, -INF);

	for (int i = 0; i < n; ++i) {
		dp1[i][i] = max(a[1], 0); // partial
		dp3[i][i][1] = 0, dp3[i][i][0] = a[1]; // random bullshit from fucking nowhere
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			for (int x = 1; x <= j - i + 1; ++x) {
				for (int k = i + 1; k <= j; ++k) {
					dp3[i][j][x] = max(dp3[i][j][x], dp3[i][k - 1][0] + dp3[k][j][x]);
					dp3[i][j][x] = max(dp3[i][j][x], dp3[i][k - 1][x] + dp3[k][j][0]);
				}
				if (j - i > 1 && x > 1 && s[i] == s[j]) {
					dp3[i][j][x] = max(dp3[i][j][x], dp3[i + 1][j - 1][x - 2]);
				}
				if (j - i == 1 && x == 2 && s[i] == s[j]) {
					dp3[i][j][x] = 0;
				}
				dp3[i][j][0] = max(dp3[i][j][0], a[x] + dp3[i][j][x]);
			}
			dp1[i][j] = max(0, dp3[i][j][0]);
			for (int k = i + 1; k <= j; ++k) {
				dp1[i][j] = max(dp1[i][j], dp1[i][k - 1] + dp1[k][j]);
			}
		}
	}

	cout << dp1[0][n - 1];
}
