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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    vector<double> dp(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        vector<double> child;
        child.reserve(g[v].size());
        for (auto &u : g[v]) {
            if (u == p) continue;
            dfs(u, v);
            child.emplace_back(dp[u] + 1);
        }
        int cnt = (int) child.size();
        double prob = 1.0 / cnt;
        for (auto &i : child) {
            dp[v] += prob * i;
        }
    };
    dfs(0, -1);
    cout << fixed << setprecision(15) << dp[0];
    return 0;
}
