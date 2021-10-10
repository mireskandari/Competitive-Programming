#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10, SQ = 410, BLOCK = 250;

int n, m, a[N];
set<int> pos[N];
pair<int, int> b[N];
long long fen[BLOCK][N], sum[N];

void update(int b, int i, int x) {
	sum[b] += x;
	for (++i; i < N; i += i & -i) {
		fen[b][i] += x;
	}
}

long long query(int b, int i) {
	long long res = 0;
	for (++i; i > 0; i -= i & -i) {
		res += fen[b][i];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		pos[i].insert(0);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].insert(i);
	}
	for (int i = 1; i <= n; ++i) {
		auto p = prev(pos[a[i]].find(i));
		b[i] = {*p, i - *p};
		update(i / SQ, b[i].first, b[i].second);
	}	

	while (m--) {
		int op, u, v;
		cin >> op >> u >> v;
		if (op == 1) {
			if (a[u] == v) {
				continue;
			}
			{
				auto p = pos[a[u]].find(u);
				update(u / SQ, *prev(p), *prev(p) - u);
				if (p != prev(pos[a[u]].end())) {
					update(*next(p) / SQ, u, u - *next(p));
					update(*next(p) / SQ, *prev(p), *next(p) - *prev(p));
					b[*next(p)] = {*prev(p), *next(p) - *prev(p)};
				}
			}
			{
				auto p = pos[v].lower_bound(u);
				update(u / SQ, *prev(p), u - *prev(p));
				b[u] = {*prev(p), u - *prev(p)};
				if (p != pos[v].end()) {
					update(*p / SQ, *prev(p), *prev(p) - *p);
					update(*p / SQ, u, *p - u);
					b[*p] = {u, *p - u};
				}
			}
			pos[a[u]].erase(u);
			pos[v].insert(u);
			a[u] = v;
		} else {
			int lb = u / SQ, rb = v / SQ;
			long long ans = 0;
			if (lb == rb) {
				for (int i = u; i <= v; ++i) {
					if (u <= b[i].first) {
						ans += b[i].second;
					}
				}
			} else {
				for (int i = u, en = (lb + 1) * SQ; i < en; ++i) {
					if (u <= b[i].first) {
						ans += b[i].second;
					}
				}
				for (int i = lb + 1; i < rb; ++i) {
					ans += sum[i] - query(i, u - 1);
				}
				for (int i = rb * SQ; i <= v; ++i) {
					if (u <= b[i].first) {
						ans += b[i].second;
					}
				}
			}
			cout << ans << '\n';
		}
	}
}