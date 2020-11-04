#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
template <class T> inline int size(T& a) { return (int)a.size(); }

template <class T>
void Read(T& a) {
	a = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) {
		a = (a << 3) + (a << 1) + (T)(c - '0');
	}
}

const int N = 105;
const int M = (1 << 20) + 2;
const i64 INF = 2e18;

int n, m, b;
int mask[N], x[N], k[N];
i64 dp[M][2], new_dp[M][2];

void Sort() {
	static int tmp[N], nmask[N], nx[N], nk[N];
	iota(tmp, tmp + n, 0);
	sort(tmp, tmp + n, [&](int& l, int& r) {
		return k[l] < k[r];
	});
	for (int i = 0; i < n; ++i) {
		nmask[i] = mask[tmp[i]];
		nx[i] = x[tmp[i]];
		nk[i] = k[tmp[i]];
	}
	swap(mask, nmask);
	swap(x, nx);
	swap(k, nk);
}

int main() {
	Read(n);
	Read(m);
	Read(b);
	for (int i = 0; i < n; ++i) {
		int sz;
		Read(x[i]);
		Read(k[i]);
		Read(sz);
		for (int j = 0; j < sz; ++j) {
			int u;
			Read(u);
			--u;
			mask[i] ^= 1 << u;
		}
	}
	Sort();
	fill_n(&dp[0][0], 2 * M, INF);
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int p = mask[0]; p > 0; --p &= mask[0]) {
		dp[p][0] = 1ll * b * k[0] + x[0];
		dp[p][1] = x[0];
	}
	for (int i = 1; i < n; ++i) {
		for (int p = 0; p < (1 << m); ++p) {
			new_dp[p][0] = min(dp[p][0], 1ll * k[i] * b + dp[p ^ (p & mask[i])][1] + x[i]);
			new_dp[p][1] = min(dp[p][1], dp[p ^ (p & mask[i])][1] + x[i]);
		}
		swap(dp, new_dp);
	}
	if (dp[(1 << m) - 1][0] >= INF)
		puts("-1");
	else
		printf("%lld", dp[(1 << m) - 1][0]);
	return 0;
}
