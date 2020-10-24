#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int64 k;
		int x;
		scanf("%lld %d", &k, &x);
		printf("%lld\n", 9ll * (k - 1) + x);
	}
	return 0;
}
