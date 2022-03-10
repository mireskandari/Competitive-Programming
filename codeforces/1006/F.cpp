#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 21;

map<long long, int> dp[N][N];
map<long long, int> tmp[N][N];

long long k, a[N][N];
int n, m, dx[2], dy[2];

void solve(int x, int y, long long d, int cnt) {
	if (cnt == 0) {
		dp[x][y][d]++;
		return;
	}
	for (int i = 0; i < 2; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny < m && ny >= 0) {
			solve(nx, ny, d ^ a[nx][ny], cnt - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	
	dx[0] = 1;
	dy[1] = 1;
	solve(0, 0, a[0][0], (n + m - 2) / 2);
	
	swap(tmp, dp);
	dx[0] = -1;
	dy[1] = -1;
	solve(n - 1, m - 1, a[n - 1][m - 1], (n + m - 2) - (n + m - 2) / 2);
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((int) dp[i][j].size() < (int) tmp[i][j].size()) {
				for (auto &x : dp[i][j]) {
					ans += 1ll * x.second * tmp[i][j][k ^ x.first ^ a[i][j]];
				}
			} else {
				for (auto &x : tmp[i][j]) {
					ans += 1ll * x.second * dp[i][j][k ^ x.first ^ a[i][j]];
				}
			}
		}
	}

	cout << ans;
}