#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr int N = 5010;

char s[N];
char t[N];
int dp[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s%s", s + 1, t + 1);
	fill_n((int *) dp, N * N, -1e7);
	dp[0][0] = 0;
	for (int i = 1; i <= m; ++i)
		dp[0][i] = -i;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = -i;
		for (int j = 1; j <= m; ++j) {
			if (s[i] == t[j]) {
				dp[i][j] = max({2, 2 + dp[i - 1][j - 1]});
			} else {
				dp[i][j] = max({dp[i - 1][j] - 1, dp[i][j - 1] - 1, -2});
			}
//			cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}
	int mx = (int) -1e7;
	for (int i = 0; i <= n; ++i)
		mx = max(mx, *max_element(dp[i], dp[i] + N));
	cout << mx;
	return 0;
}

