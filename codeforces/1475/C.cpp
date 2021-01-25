#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		vector<int> boy(a), girl(b);
		vector<pair<int, int>> in(k);
		for (int i = 0; i < k; ++i) {
			int aa;
			scanf("%d", &aa);
			boy[--aa]++;
			in[i].first = aa;
		}
		for (int i = 0; i < k; ++i) {
			int bb;
			scanf("%d", &bb);
			girl[--bb]++;
			in[i].second = bb;
		}
		long long ans = 0;
		for (int i = 0; i < k; ++i) {
			ans += (k - boy[in[i].first] - girl[in[i].second] + 1);
		}
		printf("%lld\n", ans / 2);
	}
}