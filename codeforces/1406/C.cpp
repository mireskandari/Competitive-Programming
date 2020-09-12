#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif
#define all(v) (v).begin(), (v).end()
using ll = long long;
}
using namespace Util;


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int v, u;
            cin >> v >> u;
            g[--v].emplace_back(--u);
            g[u].emplace_back(v);
        }
        vector<int> centroid, sz(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            bool c = true;
            for (int &u : g[v]) {
                if (u == p) continue;
                dfs(u, v);
                sz[v] += sz[u];
                if (sz[u] > n / 2) c = false;
            }
            if (n - sz[v] - 1 > n / 2) c = false;
            sz[v]++;
            if (c) centroid.emplace_back(v);
        };
        dfs(0, -1);
        dbg(centroid.size());
        for (auto &i : sz) dbg(i);
        if ((int) centroid.size() == 1) {
            dbg(g[0].size());
            cout << 1 << ' ' << g[0][0] + 1 << '\n';
            cout << 1 << ' ' << g[0][0] + 1 << '\n';
            continue;
        }
        int v = centroid[0], u = centroid[1];
        cout << u + 1 << ' ' << (g[u][0] == v ? g[u][1] : g[u][0]) + 1 << '\n';
        cout << v + 1 << ' '<< (g[u][0] == v ? g[u][1] : g[u][0]) + 1 << '\n';
    }
    return 0;
}