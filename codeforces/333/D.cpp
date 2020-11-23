#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr int N = 1010, TOF_N = N * N;

int n, m, a[N][N];
bool ok[N][N];

inline bool Check(int mid) {
	memset(ok, 0, sizeof(ok));
	for (int i = 0; i < n; ++i) {
		vector<int> idx;
		idx.reserve(m);
		for (int j = 0; j < m; ++j) if (a[i][j] >= mid) idx.push_back(j);
		for (int j = 0; j < len(idx); ++j) {
			for (int k = 0; k < j; ++k) {
				if (ok[idx[j]][idx[k]]) return true;
				ok[idx[j]][idx[k]] = true;
			}
		}
	}
	return false;
}

inline void Solve() {
	int l = 0, r = 1e9 + 10;
	while (r - l > 0) {
		int mid = (r + l + 1) >> 1;
		if (Check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%d", l);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	Solve();
	return 0;
}

