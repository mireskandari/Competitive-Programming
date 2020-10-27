#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] -= i; // to convert "strictly increasing" to "non-decreasing"
	}
	vector<bool> b(n);
	if (k > 0) {
		for (int i = 0; i < k; ++i) {
			int idx;
			scanf("%d", &idx);
			b[--idx] = true;
		}
	}
	auto Fuck = [] { 
		puts("-1");
		exit(0);
	};
	int max_b = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (b[i]) {
			if (a[i] < max_b) {
				Fuck();
			} else {
				max_b = a[i];
			}
		}
	}
	auto Solve = [&](int l, int r, int val_l, int val_r) {
		vector<int> dp;
		for (int i = l; i < r; ++i) {
			if (a[i] < val_l || a[i] > val_r) {
				continue;	
			}
			auto it = upper_bound(dp.begin(), dp.end(), a[i]);
			if (it == dp.end()) {
				dp.push_back(a[i]);
			} else if (*it > a[i]) {
				*it = a[i];
			}
		}
		return r - l - (int)dp.size();
	};
	int prv = 0;
	int ans = 0;
	int prv_val = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (b[i]) {
			if (i > 0) {
				ans += Solve(prv, i, prv_val, a[i]);
			}
			prv = i + 1;
			prv_val = a[i];
		}
	}
	ans += Solve(prv, n, prv_val, INT_MAX);
	printf("%d", ans);
	return 0;
}
