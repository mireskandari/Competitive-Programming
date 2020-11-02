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
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int rlast = 0, llast = a[0];
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			if (a[i] < rlast) {
				ok = false;
				break;
			}
			a[i] -= rlast;
			if (a[i] > llast) {
				rlast += a[i] - llast;
				a[i] = llast;
			}
			llast = a[i];
		}
		if (!ok) {
			puts("NO");
		} else {
			puts("YES");
		}
	}
	return 0;
}
