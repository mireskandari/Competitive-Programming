#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 5010;

int n;
int a[N][2];
short color[N];

int Dist(int i, int j) {
	return abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
}

bool Dfs(int v, short c, int d) {
	color[v] = c;
	for (int u = 0; u < n; ++u) {
		if (u == v) {
			continue;
		}
		if (Dist(u, v) <= d) {
			continue;
		}
		if (color[u] == -1) {
			if (!Dfs(u, !c, d)) {
				return false;
			}
		} else if (color[u] == c) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	auto Solve = [&](int d) {
		memset(color, -1, sizeof(color));
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (color[i] == -1) {
				++cnt;
				if (!Dfs(i, 0, d)) {
					return -1;
				}
			}
		}
		constexpr int MO = 1000000007;
		int x = 2;
		int res = 1;
		for (; cnt > 0; cnt >>= 1, x = (1ll * x * x) % MO) {
			if (cnt & 1) {
				res = (1ll * res * x) % MO;
			}
		}
		return res;
	};	
	int low = 0, high = 3 * N;
	while (high - low > 1) {
		int mid = (low + high) >> 1;
		if (Solve(mid) == -1) {
			low = mid;
		} else {
			high = mid;
		}
	}
	low = Solve(low) == -1 ? high : low;
	printf("%d\n%d", low, Solve(low));
	return 0;
}
