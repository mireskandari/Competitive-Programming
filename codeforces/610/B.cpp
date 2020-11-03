#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int mn = *min_element(a.begin(), a.end());
	i64 ans = n * mn;
	deque<int> q(a.begin(), a.end());
	int idx = 0;
	while (idx < n && a[idx] > mn) ++idx;
	for (int i = n - 1; i >= 0; --i) {
		int s = q.back();
		q.pop_back();
		q.push_front(s);
		if (s == mn) {
			idx = 0;
		} else {
			++idx;
		}
		ans = max(ans, 1ll * n * mn + idx);
	}
	printf("%lld", ans);
	return 0;
}
