#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

struct Node {
	int p, s, mx, size;

	Node(int a = 0, int u = 0, int v = 0) : p(a), s(a), mx(a), size(v - u) {}
};

Node t[N << 2];

void build(int c, int b, int e) {
	t[c].p = t[c].s = t[c].mx = 0;
	t[c].size = e - b;
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1;
	build(c << 1, b, m);
	build(c << 1 | 1, m, e);
}

void pull(Node &c, Node l, Node r, bool change) {
	c.p = l.p + (l.p == l.size ? r.p : 0);
	c.s = r.s + (r.s == r.size ? l.s : 0);
	if (change) {
		c.size = l.size + r.size;
	}
	c.mx = max({l.mx, r.mx, l.s + r.p});
}

void update(int c, int b, int e, int i) {
	if (e - b == 1) {
		t[c].p = 1;
		t[c].s = 1;
		t[c].mx = 1;
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (i < m) {
		update(l, b, m, i);
	} else {
		update(r, m, e, i);
	}
	pull(t[c], t[l], t[r], false);
}

Node query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	Node ret(0);
	if (u < m) {
		if (v > m) {
			pull(ret, query(l, b, m, u, v), query(r, m, e, u, v), true);
		} else {
			ret = query(l, b, m, u, v);
		}
	} else {
		ret = query(r, m, e, u, v);
	}
	return ret;
}

void show(int c, int b, int e) {
	cerr << b << ' ' << e << ' ' << t[c].p << ' ' << t[c].s << ' ' << t[c].mx << ' ' << t[c].size << '\n';
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1;
	show(c << 1, b, m);
	show(c << 1 | 1, m, e);
}

int n, m;
int h[N], low[N], mid[N], high[N];
pair<int, int> sh[N];

tuple<int, int, int> qq[N];
vector<int> qry[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	build(1, 0, n);
	//show(1, 0, n);

	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		sh[i] = {h[i], i};
	}
	sort(sh, sh + n, greater<pair<int, int>>());
	int unique_size = (int) set<int>(h, h + n).size();
	
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> get<0>(qq[i]) >> get<1>(qq[i]) >> get<2>(qq[i]);
		--get<0>(qq[i]);
		low[i] = 0;
		high[i] = unique_size - 1;
	}
	
	for (int l = 0; l < 23; ++l) {
		//cerr << "CURRENTLY AT: " << l << '\n';
		fill(qry, qry + n, vector<int>());
		build(1, 0, n);

		for (int i = 0; i < m; ++i) {
			//cerr << "    QUERY: " << i << " ANS IS = " << low[i] << ' ' << high[i] << '\n';
			mid[i] = (low[i] + high[i]) >> 1;
			qry[mid[i]].push_back(i);
		}

		for (int i = 0, j = 0, x = 0; i < n; i = j, ++x) {
			while (j < n && sh[j].first == sh[i].first) {
				update(1, 0, n, sh[j++].second);
			}
			
			for (auto &q : qry[x]) {
				int l = get<0>(qq[q]), r = get<1>(qq[q]), w = get<2>(qq[q]);
				if (query(1, 0, n, l, r).mx >= w) {
					//cerr << "KIR\n";
					high[q] = x;
				} else {
					low[q] = x + 1;
				}
			}
			//cerr << "KIRESAG TO KOSE NANAT: " << i << ' ' << j << '\n';
			//show(1, 0, n);
		}
	}
	
	vector<int> temp(h, h + n);
	for (int i = 0; i < n; ++i) {
		temp[i] = -temp[i];
	}
	sort(temp.begin(), temp.end());
	temp.resize(unique(temp.begin(), temp.end()) - temp.begin());


	for (int i = 0; i < m; ++i) {
		//cerr << low[i] << '\n';
		cout << -temp[low[i]] << '\n';
	}
}