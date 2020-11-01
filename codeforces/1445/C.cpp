#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int64 p, q;
		scanf("%lld%lld", &p, &q);
		if (p % q != 0) {
			printf("%lld\n", p);
		} else {
			if (q == 1) {
				puts("1");
			} else {
				map<int64, int64> factor;
				for (int64 i = 2; i * i <= q; ++i) {
					if (q % i == 0) {
						factor[i] = 1;
						while (q % i == 0) {
							factor[i] *= i;
							q /= i;
						}
					}
				}
				if (q > 1) factor[q] = q;
				vector<int64> cand;
				for (auto [a, b] : factor) {
					cand.push_back(p);
					while (cand.back() % b == 0) {
						cand.back() /= a;
					}
				}
				printf("%lld\n", *max_element(cand.begin(), cand.end()));
			}
		}
	}
	return 0;
}
