#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 2e5 + 10;

int a[N];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		vector<vector<int>> segs;
		for (int i = 1; i < n; ++i) {
			if (!segs.empty() && segs.back().back() < a[i]) {
				segs.back().push_back(a[i]);
			} else {
				segs.emplace_back(1, a[i]);
			}
		}
		int depth = 1;
		int last_size = 1;
		int segs_size = 0;
		int now = 0;
		for (auto& seg : segs) {
			if (now < last_size) {
				now++;
				segs_size += (int)seg.size();
			} else {
				depth++;
				now = 1;
				last_size = segs_size;
				segs_size = (int)seg.size();
			}
		}
		printf("%d\n", depth);

	}
	return 0;
}
