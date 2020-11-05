#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
template <class T>
inline int size(T& a) { return (int)a.size(); }

const int MOD = 998244353;

void Mult(int& a, int b) {
	a = 1ll * a * b % MOD;
}

const int N = 2e5 + 10;

int n, k;
int a[N], b[N], where[N];
bool is[N];

int main() {
	int tc;
	scanf("%d", &tc);
	for (; tc > 0; --tc) {
		scanf("%d%d", &n, &k);
		memset(is, false, sizeof(bool) * n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			where[a[i]] = i;
		}
		for (int i = 1; i <= k; ++i) {
			scanf("%d", &b[i]);
			is[b[i]] = true;
		}
		set<int> idx;
		for (int i = 1; i <= n; ++i) {
			idx.insert(i);
		}
		int ans = 1;
		auto Prv = [&](int i) {
			auto p = idx.lower_bound(i);
			if (p == idx.begin()) return 0;
			return *prev(p);
		};
		auto Nxt = [&](int i) {
			auto p = idx.upper_bound(i);
			if (p == idx.end()) return n + 1;
			return *p;
		};
		for (int i = 1; i <= k; ++i) {
			int j = where[b[i]];
			vector<int> who;
			if (Prv(j) != 0 && !is[a[Prv(j)]])
				who.push_back(Prv(j));
			if (Nxt(j) != n + 1 && !is[a[Nxt(j)]])
				who.push_back(Nxt(j));
			is[a[j]] = false;
			Mult(ans, size(who));
			if (!who.empty())
				idx.erase(who.front());
		}
		printf("%d\n", ans);
	}
	return 0;
}
