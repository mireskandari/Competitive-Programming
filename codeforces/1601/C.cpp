#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e6 + 10;

struct Node {
	int lz, mn, mni;

	Node() {}
	Node(int mn, int mni) : lz(0), mn(mn), mni(mni) {}

	inline void apply(int x) {
		mn += x;
		lz += x;
	}
};

Node t[N << 2];

void pull(int c, int l, int r) {
	t[c].mn = min(t[l].mn, t[r].mn);
	t[c].mni = t[c].mn == t[l].mn ? t[l].mni : t[r].mni;
}

int n, m;

void build(int c, int b, int e) {
	if (e - b == 1) {
		t[c].mn = b;
		t[c].mni = b;
		t[c].lz = 0;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	t[c].mn = b;
	t[c].mni = b;
	t[c].lz = 0;
}

void update(int c, int b, int e, int u, int x) {
	if (n + 1 <= b || e <= u) {
		return;
	}
	if (u <= b) {
		t[c].apply(x);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].lz != 0) {
		t[l].apply(t[c].lz);
		t[r].apply(t[c].lz);
		t[c].lz = 0;
	}
	update(l, b, m, u, x);
	update(r, m, e, u, x);
	pull(c, l, r);
}

void show(int c, int b, int e) {
	cerr << "NODE " << b << ',' << e - 1 << ": " << t[c].mn << ' ' << t[c].mni << '\n';
	if (e - b == 1) {
		return;
	}
	show(c << 1, b, (b + e) >> 1);
	show(c << 1 | 1, (b + e) >> 1, e);
}

pair<int, int> a[N];
vector<int> res[N];
int ans[N], tmp[N];

long long solve(int l, int r) {
	if (r - l == 1) {
		return 0;
	}
	int m = (l + r) >> 1;
	long long res = solve(l, m) + solve(m, r);
	int ptr = l, ll = l, rr = m;
	while (ptr < r) {
		int vl = ll == m ? INT_MAX : ans[ll];
		int vr = rr == r ? INT_MAX : ans[rr];
		if (vl <= vr) {
			tmp[ptr++] = vl;
			++ll;
		} else {
			tmp[ptr++] = vr;
			++rr;
			res += m - ll;
		}
	}
	for (int i = l; i < r; ++i) {
		ans[i] = tmp[i];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		
		fill(res, res + n + 1, vector<int>());
		build(1, 0, n + 1);
		//show(1, 0, n + 1);

		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			a[i] = make_pair(x, -i - 1);
			res[i + 1].push_back(x);
		}
		for (int i = 0; i < m; ++i) {
			int x;
			cin >> x;
			a[i + n] = make_pair(x, 0);
		}
		
		sort(a, a + n + m);

		for (int i = 0, j = 0; i < n + m; i = j) {
			while (j < n + m && a[i].first == a[j].first) {
				++j;
			}
			int c = 0;
			for (int k = i; k < j; ++k) {
				if (a[k].second < 0) {
					//cerr << -a[k].second << ' ' << -1 << '\n';
					update(1, 0, n + 1, -a[k].second, -1);
				} else {
					++c;
				}
			}
			update(1, 0, n + 1, t[1].mni, -c);
			while (c--) {
				res[t[1].mni].push_back(a[i].first);
			}
			//cerr << a[i].first << ' ' << t[1].mni << '\n';
			//cerr << a[i].first << ' ' << t[1].mni << '\n';
			for (int k = i; k < j; ++k) {
				if (a[k].second < 0) {
					//cerr << -a[k].second << ' ' << -1 << '\n';
					update(1, 0, n + 1, -a[k].second, -1);
				}
			}

			//show(1, 0, n + 1);
		}
		 
		
		int t = 0;
		for (int i = 0; i < n + 1; ++i) {
			for (auto &x : res[i]) {
			//	cout << x << ' ';
				ans[t++] = x;
			}
		}
		//cout << '\n';
		cout << solve(0, n + m) << '\n';
		//for (int i = 0; i < n + m; ++i) {
		//	cout << tmp[i] << ' ';
		//}
	}
}