#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 600, MAX = 25e4 + 10;

int table[N][N], row[N][N], col[N][N], row_order[N];
int row_pos[MAX];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &row[i][j]);
				row_pos[row[i][j]] = i;
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &col[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			row_order[i] = row_pos[col[0][i]];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%d ", row[row_order[i]][j]);
			}
			puts("");
		}
	}
	return 0;
}
