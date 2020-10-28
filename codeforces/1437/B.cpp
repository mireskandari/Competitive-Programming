#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 1e5 + 10;

char s[N];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		scanf("%s", s);
		int zans = 0, oans = 0, one = 0, zero = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (one > 0) {
					oans += one - 1;
				}
				one = 0;
				zero++;
			} else {
				if (zero > 0) {
					zans += zero - 1;
				}
				zero = 0;
				one++;
			}
		}
		printf("%d\n", max(zans, oans));
	}
	return 0;
}
