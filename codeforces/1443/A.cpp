#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = n + 1; i <= 2 * n; ++i) {
			printf("%d ", 2 * i);
		}
		puts("");
	}
	return 0;
}
