#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")

int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 1) puts("0"), exit(0);
	int d = n / 2;
	if (d & 1) {
		printf("%d", d / 2);
	} else {
		printf("%d", (d - 1) / 2);
	}
	return 0;
}
