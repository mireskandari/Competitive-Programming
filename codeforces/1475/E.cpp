#include <bits/stdc++.h>
using namespace std;

constexpr int MD = 1000 * 1000 * 1000 + 7;

int ncr[1010][1010];

int main() {
	ncr[0][0] = 1;
	for (int i = 0; i < 1010; ++i) {
		for (int j = 0; j < 1010; ++j) {
			if (!(i + j)) {
				continue;
			}
			ncr[i][j] = i > 0 ? ncr[i - 1][j] : 0;
			(ncr[i][j] += i > 0 && j > 0 ? ncr[i - 1][j - 1] : 0) %= MD;
		}
	}
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k;
		scanf("%d%d", &n, &k);
		map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d", &a);
			mp[--a]++;
		}
		long long ans = 1;
		for (auto it = mp.rbegin(); it != mp.rend() && k; ++it) {
			ans *= ncr[it->second][min(k, it->second)];
			if (k < it->second) {
				break;
			}
			k -= it->second;
		}
		printf("%lld\n", ans);
	}
}
