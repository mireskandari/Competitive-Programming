#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int N = 5e2 + 10;

int n, x[N];
bool added[N];
long long dist[N][N];
long long ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%lld", &dist[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		--x[i];
	}

	for (int k = n - 1; k >= 0; --k) {
		added[x[k]] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][x[k]] + dist[x[k]][j]);
				if (added[i] && added[j]) {
					ans[k] += dist[i][j];
				}
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		printf("%lld ", ans[i]);
	}
	return 0;
}

