#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 5e5 + 10, Q = 5e4 + 10;
constexpr int SQ = 500, BLOCKS = N / SQ + 10;

int n, q, a[N];

long long added[BLOCKS];
vector<pair<long long, int>> p[BLOCKS];

inline void take_care(int b, int l, int r, int x) {
	vector<pair<long long, int>> nw;
	for (auto &v : p[b]) {
		if (l <= v.second && v.second <= r) {
			nw.push_back({v.first + x, v.second});
		} else {
			nw.push_back(v);
		}
	}
	sort(nw.begin(), nw.end());
	swap(nw, p[b]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		p[i / SQ].push_back({a[i], i});
	}
	for (int i = 0, e = (n - 1) / SQ + 1; i < e; ++i) {
		sort(p[i].begin(), p[i].end());
	}

	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			--l, --r;
			if (x == 0) {
				continue;
			}
			int bl = l / SQ, br = r / SQ;
			if (bl == br) {
				take_care(bl, l, r, x);
			} else {
				take_care(bl, l, (bl + 1) * SQ - 1, x);
				for (int i = bl + 1; i < br; ++i) {
					added[i] += x;
				}
				take_care(br, br * SQ, r, x);
			}
		} else {
			int x;
			cin >> x;
			int mn = INT_MAX, mx = INT_MIN;
			for (int i = 0, e = (n - 1) / SQ + 1; i < e; ++i) {
				long long xx = x - added[i];
				auto f = lower_bound(p[i].begin(), p[i].end(), make_pair(xx, INT_MIN));
				auto s = upper_bound(p[i].begin(), p[i].end(), make_pair(xx, INT_MAX));
				
				if (f == p[i].end() || f->first != xx) {
					continue;
				}
				
				--s;
				assert(s->first == xx && f->first == xx);
				mn = min(mn, f->second);
				mx = max(mx, s->second);
			}
			cout << (mx == INT_MIN ? -1 : mx - mn) << '\n';
		}
	}
}