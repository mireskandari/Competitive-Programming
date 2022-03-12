#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int maxn = 5e5 + 10;

int key[maxn], val[maxn], it1;
int spf[maxn];
bool bad[maxn];

int cnt[maxn];

int n, q;
vector<pair<int, int>> a[maxn];

bool in[maxn];

int main() {
	for (int i = 2; i < maxn; ++i) {
		if (!spf[i]) {
			spf[i] = i;
			for (int j = i << 1; j < maxn; j += i) {
				if (!spf[j]) {
					spf[j] = i;
				}
			}
		}
	}
	
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		vector<int> vec;
		while (x > 1) {
			vec.push_back(spf[x]);
			x /= spf[x];
		}
		sort(vec.begin(), vec.end());
		vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

		for (int j = 1; j < (1 << len(vec)); ++j) {
			int res = 1, p = 1;
			for (int y = 0; y < len(vec); ++y) {
				if ((j >> y) & 1) {
					res *= vec[y];
					p *= -1;
				}
			}
			a[i].push_back({res, p});
		}
	}
	
	long long ans = 0;
	int cntin = 0;

	while (q--) {
		int x;
		scanf("%d", &x);
		--x;

		int delta = cntin - in[x];
		for (auto &d : a[x]) {
			delta += d.second * (cnt[d.first] - in[x]);
			cnt[d.first] += in[x] ? -1 : 1;
		}

		if (in[x]) {
			cntin--;
			ans -= delta;
			in[x] = false;
		} else {
			cntin++;
			ans += delta;
			in[x] = true;
		}

		printf("%lld\n", ans);
	}
}