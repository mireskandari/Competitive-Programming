#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

pair<long long, long long> t[N << 2];

void push(int c, int b, int e) {
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].second > 0) {
		t[l].first += 1ll * (m - b) * t[c].second;
		t[l].second += t[c].second;
		t[r].first += 1ll * (e - m) * t[c].second;
		t[r].second += t[c].second;
		t[c].second = 0;
	}
}

void update(int c, int b, int e, int u, int v, int x) {
	if (u <= b && e <= v) {
		t[c].first += 1ll * (e - b) * x;
		t[c].second += x;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, b, e);
	if (u < m) {
		update(l, b, m, u, v, x);
	}
	if (v > m) {
		update(r, m, e, u, v, x);
	}
	t[c].first = t[l].first + t[r].first;
}

long long query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c].first;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, b, e);
	long long ret = 0;
	if (u < m) {
		ret += query(l, b, m, u, v);
	}
	if (v > m) {
		ret += query(r, m, e, u, v);
	}
	return ret;
}

void show(int c, int b, int e) {
	cerr << "NODE L, R, X: " << b << ' ' << e - 1 << ' ' << t[c].first << '\n';
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1;
	show(c << 1, b, m);
	show(c << 1 | 1, m, e);
}

int n, m;
set<pair<pair<int, int>, int>> gg;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		gg.insert({{i, i}, i + 1});
	}

	while (m--) {
		int op, l, r;
		cin >> op >> l >> r;
		--l, --r;
		if (op == 1) {
			//cerr << "CHANGING : " << l << ' ' << r << '\n';
			int x;
			cin >> x;
			auto p = gg.lower_bound(make_pair(make_pair(l, INT_MAX), INT_MAX));
			auto q = gg.lower_bound(make_pair(make_pair(r, INT_MAX), INT_MAX));
			assert(p != gg.begin());
			assert(q != gg.begin());
			if (p != q) {
			//	cerr << "SHIT\n";
				--p;
				--q;
				vector<pair<pair<int, int>, int>> tmp;
				for (auto it = next(p); it != q; ++it) {
					tmp.push_back(*it);
				//	cerr << "UPDATINGGGGGG : " << it->first.first << ' ' << it->first.second << ' ' << abs(it->second - x) << '\n';
					update(1, 0, n, it->first.first, it->first.second + 1, abs(it->second - x));
				}
				int l1 = p->first.first, r1 = p->first.second, x1 = p->second;
				int l2 = q->first.first, r2 = q->first.second, x2 = q->second;
				//cerr << "UPDATING : " << l << ' ' << r1 << ' ' << abs(x1 - x) << '\n';
				update(1, 0, n, l, r1 + 1, abs(x1 - x));
			//	cerr << "UPDATING : " << l2 << ' ' << r << ' ' << abs(x2 - x) << '\n';
				update(1, 0, n, l2, r + 1, abs(x2 - x));

				for (auto &tt : tmp) {
					gg.erase(tt);
				}
				gg.erase({{l1, r1}, x1});
				gg.erase({{l2, r2}, x2});
				
				if (l1 <= l - 1) {
					gg.insert({{l1, l - 1}, x1});
				}
				if (r + 1 <= r2) {
					gg.insert({{r + 1, r2}, x2});
				}
				gg.insert({{l, r}, x});
			} else {
			//	cerr << "SHIT2\n";
				--p;
				int ll = p->first.first, rr = p->first.second, xx = p->second;
				if (xx == x) {
					continue;
				}
				gg.erase(p);
				if (ll <= l - 1) {
					gg.insert({{ll, l - 1}, xx});
				}
				if (r + 1 <= rr) {
					gg.insert({{r + 1, rr}, xx});
				}
				gg.insert({{l, r}, x});
			//	cerr << "UPDATING : " << l << ' ' << r << ' ' << abs(xx - x) << '\n';
				update(1, 0, n, l, r + 1, abs(xx - x));
			}
		} else {
			cout << query(1, 0, n, l, r + 1) << '\n';
		}
	/*	cerr << "SEGMENTS:\n";
		for (auto &pp : gg) {
			cerr << "L, R, X: " << pp.first.first << ' ' << pp.first.second << ' ' << pp.second << '\n';
		}
		cerr << "\n\n\n\n";
		show(1, 0, n);*/
	}
}