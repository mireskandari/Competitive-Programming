#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int l, r;
		scanf("%d %d", &l, &r);
		if ((r + 2) / 2 <= l) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
