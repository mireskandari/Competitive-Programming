#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				printf("%d ", -a[i - 1]);
			} else {
				printf("%d ", a[i + 1]);
			}
		}
		puts("");
	}
	return 0;
}
