#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 2e5 + 10;

int a[N];
char s[N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%s", s + 1);
	int64 ans = 0;
	for (int i = 1; i <= n; ) {
		int j;
		for (j = i; j <= n && s[i] == s[j]; ++j) {}
		multiset<int, greater<>> st;
		for (; i < j; ++i) {
			st.insert(a[i]);
		}
		int cnt = 1;
		for (auto& val : st) {
			if (cnt > k) break;
			ans += val;
			++cnt;
		}
	}
	printf("%lld", ans);
	return 0;
}
