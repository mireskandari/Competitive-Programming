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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		vector<int> idx(n);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&](int x, int y) {
			return a[x] < a[y];
		});
		{
			vector<int> bb(n), aa(n);
			for (int i = 0; i < n; ++i) {
				bb[i] = b[idx[i]];
				aa[i] = a[idx[i]];
			}
			swap(bb, b);
			swap(aa, a);
		}
		assert(is_sorted(a.begin(), a.end()));
		i64 low = 0, high = 1e15;
		auto Solve = [&](i64 mid) {
			auto pos = upper_bound(a.begin(), a.end(), mid);
			if (pos == a.end()) return true;
			int p = pos - a.begin();
			i64 sum = 0;
			for (int i = p; i < n; ++i) {
				sum += b[i];
			}
			if (p == 0) {
				if (sum <= mid) {
					return true;
				} else {
					return false;
				}
			} else {
				if (sum > mid) {
					return false;
				} else {
					return true;
				}
			}
		};
		while (high - low >= 1) {
			i64 mid = (high + low) / 2;
			if (Solve(mid)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		printf("%lld\n", low);
	}
	return 0;
}
