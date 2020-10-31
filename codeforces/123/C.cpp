#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")

void Ok(int64& a) { a = min((int64)1e18, a); }

const int N = 500;

int64 k, dp[N][N];
int n, m, a[N][N], p[N];
char s[N];

int main() {
	scanf("%d%d%lld", &n, &m, &k);
	memset(p, 0x3f, sizeof(p));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			p[i + j - 1] = min(p[i + j - 1], a[i][j]);
		}
	}
	auto Work = [&](int len) {
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= len; ++i) {
			for (int j = 0; j <= len / 2; ++j) {
				if (s[i] != '(') Ok(dp[i][j] += dp[i - 1][j + 1]);
				if (j > 0 && s[i] != ')') Ok(dp[i][j] += dp[i - 1][j - 1]);
			}
		}
	};
	auto Best = [&] {
		int b = -1, v = INT_MAX;
		for (int i = 1; i <= n + m - 1; ++i) {
			if (s[i] == 0 && v > p[i]) v = p[i], b = i;
		}
		return b;
	};
	for (int i = 0; i < n + m - 1; ++i) {
		int j = Best();
		s[j] = '(';
		Work(n + m - 1);
		auto num = dp[n + m - 1][0];
		if (k > num) {
			k -= num;
			s[j] = ')';
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			putchar(s[i + j - 1]);
		}
		puts("");
	}
	return 0;
}
