#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

const int MO = 998244353;

int Power(int a, int b) {
	int res = 1;
	for (; b > 0; b >>= 1, a = 1ll * a * a % MO) {
		if (b & 1) res = 1ll * res * a % MO;
	}
	return res;
}

const int N = 3e5 + 10;

int64 a[N];

int main() {
	int n;
	scanf("%d", &n);
	n *= 2;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	int64 ans = 0;
	for (int i = 0; i < n / 2; ++i) {
		ans += a[i + n / 2] - a[i];
		if (ans >= MO) ans -= MO;
	}
	int res = 1;
	for (int i = 2; i <= n; ++i) res = (1ll * res * i) % MO;
	for (int i = 2; i <= n / 2; ++i) res = (1ll * res * Power(i, MO - 2)) % MO;
	for (int i = 2; i <= n / 2; ++i) res = (1ll * res * Power(i, MO - 2)) % MO;
	printf("%lld", 1ll * ans * res % MO);
	return 0;
}
