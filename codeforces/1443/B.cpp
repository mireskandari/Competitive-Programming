#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")

const int N = 1e5 + 10;

char s[N];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b;
		scanf("%d%d%s", &a, &b, s);
		int n = (int)strlen(s);
		int first = 0;
		while (first < n && s[first] != '1') ++first;
		if (first == n) {
			puts("0");
			continue;
		}
		int ans = 0;
		for (int i = first, gap; i < n; ++i) {
			if (s[i] == '1') {
				if (i != 0 && s[i] == s[i - 1]) continue;
				if (i == first) {
					ans += a;
				} else {
					ans += min(gap * b, a);
				}
			} else {
				if (i != 0 && s[i] != s[i - 1]) gap = 0;
				++gap;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
