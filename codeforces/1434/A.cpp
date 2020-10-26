#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 1e5 + 10;

int a[10], b[N];

int main() {
	for (int i = 0; i < 6; ++i) {
		scanf("%d", &a[i]);
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	vector<pair<int, int>> diff;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 6; ++j) {
			diff.emplace_back(b[i] - a[j], i);
		}
	}
	sort(diff.begin(), diff.end());
	int ptr = -1;
	map<int, int> cnt;
	auto Dec = [&](int val) {
		if (--cnt[val] == 0) {
			cnt.erase(val);
		}
	};
	int mn = INT_MAX;
	for (int i = 0; i < (int)diff.size(); ++i) {
		if (i > 0) {
			Dec(diff[i - 1].second);
		}
		++ptr;
		auto IsBad = [&] {
			return (int)cnt.size() < n || cnt.begin()->first != 0;
		};
		while (IsBad() && ptr < (int)diff.size()) {
			cnt[diff[ptr].second]++;
			++ptr;
		}
		--ptr;
		if (IsBad()) {
			break;
		}
		mn = min(mn, diff[ptr].first - diff[i].first);
	}
	printf("%d", mn);
	return 0;
}
