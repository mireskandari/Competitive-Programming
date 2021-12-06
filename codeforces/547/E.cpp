#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 5e5 + 10;

int n, q;
int nxt[N][26], f[N], mp[N], treesize = 1;
string s[N];

void add(int i) {
	int p = 0;
	for (auto &c : s[i]) {
		if (nxt[p][c - 'a']) {
			p = nxt[p][c - 'a'];
		} else {
			nxt[p][c - 'a'] = treesize;
			p = treesize++;
		}
	}
	mp[i] = p;
}

void build_aho() {
	queue<int> q;
	for (int i = 0; i < 26; ++i) {
		if (nxt[0][i]) {
			q.push(nxt[0][i]);
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < 26; ++i) {
			if (nxt[v][i]) {
				f[nxt[v][i]] = nxt[f[v]][i];
				q.push(nxt[v][i]);
			} else {
				nxt[v][i] = nxt[f[v]][i];
			}
		}
	}
}

vector<int> g[N];
int tin[N], tout[N], timer;

void dfs(int v) {
	tin[v] = timer++;
	for (auto &u : g[v]) {
		dfs(u);
	}
	tout[v] = timer;
}

long long fen[N];

void update(int i, int x) {
	for (++i; i < N; i += i & -i) {
		fen[i] += x;
	}
}

long long query(int i) {
	long long res = 0;
	for (++i; i > 0; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

long long query(int l, int r) {
	return query(r - 1) - query(l - 1);
}

vector<pair<int, int>> queries[N];
long long ans[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		add(i);
	}

	build_aho();
	for (int i = 1; i < treesize; ++i) {
		g[f[i]].push_back(i);
	}
	dfs(0);

	for (int i = 0; i < q; ++i) {
		int l, r, k;
		cin >> l >> r >> k;
		--l, --r;
		if (l != 0) {
			queries[l - 1].push_back({-k, i});
		}
		queries[r].push_back({k, i});
	}

	for (int i = 0; i < n; ++i) {
		int p = 0;
		for (auto &c : s[i]) {
			p = nxt[p][c - 'a'];
			update(tin[p], +1);
		}
		for (auto &qu : queries[i]) {
			int k = qu.first;
			if (k < 0) {
				k = -k - 1;
				ans[qu.second] -= query(tin[mp[k]], tout[mp[k]]);
			} else {
				--k;
				ans[qu.second] += query(tin[mp[k]], tout[mp[k]]);
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}