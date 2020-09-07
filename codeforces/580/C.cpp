#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif

#define all(v) (v).begin(), (v).end()
using ll = int64_t;
}
using namespace Util;


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    vector<int> gorbe(n);
    for (int i = 0; i < n; ++i) {
        cin >> gorbe[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    
    int cnt = 0;
    vector<bool> mark(n);
    function<void(int, int, int)> dfs = [&](int v, int c, int mx) {
        mark[v] = true;
        bool leaf = true;

        for (auto &u : g[v]) {
            if (!mark[u]) {
                leaf = false;
                if (gorbe[u]) dfs(u, c + 1, max(mx, c + 1));
                else dfs(u, 0, max(mx, c));
            }
        }
        if (leaf && mx <= m) cnt++;
    };
    dfs(0, gorbe[0], gorbe[0]);

    cout << cnt;
    return 0;
}
