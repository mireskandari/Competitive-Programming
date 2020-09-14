#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(a) cerr << "\"" << #a << "\"=" << a << '\n'
#else
#define dbg(a) 0
#endif

// put the biggest numbers on the edges that appear in the most paths

int constexpr P = 1000000007;

void norm(int64_t &a) {
    if (a >= P) a -= P;
    if (a < 0) a += P;
}

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
        vector<int64_t> sz(n);
        vector<int64_t> order;
        order.reserve(n - 1);
        function<void(int, int)> dfs = [&](int v, int p) {
            sz[v] = 1;
            for (auto &u : g[v]) {
                if (u == p) continue;
                dfs(u, v);
                sz[v] += sz[u];
            }
            if (p != -1) {
                order.emplace_back(sz[v] * int64_t(n - sz[v]));
            }
        };
        dfs(0, -1);
        sort(order.begin(), order.end());
        int m;
        cin >> m;
        vector<int64_t> a(m);
        for (auto &i : a) cin >> i;
        if (m < n - 1) a.resize(n - 1, 1);
        sort(a.begin(), a.end());
        int64_t ans = order.back();
        for (int i = n - 2; i < int(a.size()); ++i) {
            (ans *= a[i]) %= P;
        }
        for (int i = 0; i < n - 2; ++i) {
            norm(ans += (order[i] * a[i]) % P);
        }
        cout << ans << '\n';
    }
    return 0;
}
