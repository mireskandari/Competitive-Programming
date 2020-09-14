#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(a) cerr << "\"" << #a << "\"=" << a << '\n'
#else
#define dbg(a) 0
#endif

int n;
vector<int> centroid, sz;
vector<vector<int>> g;

void dfs(int v, int p) {
    sz[v] = 1;
    bool cent = true;
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
        if (sz[u] > n / 2) cent = false;
    }
    if (n - sz[v] > n / 2) cent = false;
    if (cent) centroid.emplace_back(v);
}

int find_leaf(int v, int p) {
    for (auto &u : g[v]) {
        if (u == p) continue;
        int res = find_leaf(u, v);
        if (res != -1) return res;
    }
    if (int(g[v].size()) == 1) return v;
    return -1;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        centroid.clear();
        g.assign(n, vector<int>());
        sz.assign(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            int v, u;
            cin >> v >> u;
            g[--v].emplace_back(--u);
            g[u].emplace_back(v);
        }
        dfs(0, -1);
        if (int(centroid.size()) == 1) {
            cout << 1 << ' ' << g[0][0] + 1 << '\n';
            cout << 1 << ' ' << g[0][0] + 1 << '\n';
            continue;
        }
        int v = centroid[0], u = centroid[1];
        g[u].erase(find(g[u].begin(), g[u].end(), v));
        g[v].erase(find(g[v].begin(), g[v].end(), u));
        int l = find_leaf(u, -1);
        cout << l + 1 << ' ' << g[l][0] + 1 << '\n';
        cout << l + 1 << ' ' << v + 1 << '\n';
    }
    return 0;
}
