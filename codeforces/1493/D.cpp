#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int M = 1000 * 1000 * 1000 + 7;

int power(int n, int k) {
	int res = 1;
	for (; k; k >>= 1, n = 1ll * n * n % M) {
		if (k & 1) {
			res = 1ll * res * n % M;
		}
	}
	return res;
}

int spf[212345];

inline map<int, int> factor(int x) {
	map<int, int> f;
	while (spf[x] > 1) {
		f[spf[x]]++;
		x /= spf[x];
	}
	return f;
}

int a[212345], ptoi[212345];
map<int, int> ff[212345];

multiset<int> dude[21234];
int now[22234];

int itop[22234], itt;

int main() {
	
	for (int i = 2; i < 212345; ++i) {
		if (!spf[i]) {
			itop[itt++] = i;
			ptoi[i] = itt - 1;

			spf[i] = i;
			for (int j = i << 1; j < 212345; j += i) {
				if (!spf[j]) {
					spf[j] = i;
				}
			}
		}
	}
	
	int n, q;
	scanf("%d%d", &n, &q);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		ff[i] = factor(a[i]);
		for (auto &p : ff[i]) {
			dude[ptoi[p.first]].insert(p.second);
		}
	}
	
	int g = 1;

	for (int i = 0; i < itt; ++i) {
		if (len(dude[i]) == n) {
			g = 1ll * g * power(itop[i], *dude[i].begin()) % M;
			now[i] = power(itop[i], *dude[i].begin());
		}
	}
			
	while (q--) {
		int idx, x;
		scanf("%d%d", &idx, &x);
		--idx;

		auto f = factor(x);

		for (auto &p : f) {
			int mp = ptoi[p.first];
			auto pp = dude[mp].find(ff[idx][p.first]);
			if (pp != dude[mp].end()) {
				dude[mp].erase(pp);
			}
			ff[idx][p.first] += p.second;
			dude[mp].insert(ff[idx][p.first]);
			
			if (len(dude[mp]) == n) {
				if (now[mp] != 0) {
					g = 1ll * g * power(now[mp], M - 2) % M;
				}
				now[mp] = power(p.first, *dude[mp].begin());
				g = 1ll * g * now[mp] % M;
			}
		}
		
		printf("%d\n", g);
	}
}


