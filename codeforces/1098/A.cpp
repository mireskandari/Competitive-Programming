#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a) 0
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
}
using namespace Util;


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    long n; cin >> n;
    vector<vector<long>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
        int v; cin >> v;
        g[v].emplace_back(i);
        g[i].emplace_back(v);
    }
    vector<long> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    vector<long> a(n + 1);
    function<void(long, long)> dfs = [&](long v, long p) {
        long mn = LLONG_MAX;
        for (auto &u : g[v]) {
            if (u == p) continue;
            if (s[v] == -1) {
                mn = min(mn, s[u] - s[p]);
            }
        }
        if (s[v] == -1 && mn != LLONG_MAX) {
            a[v] = mn; 
            s[v] = mn + s[p];
        } else if (s[v] == -1) {
            a[v] = 0;
            s[v] = s[p];
        }
        if (a[v] < 0) {
            cout << -1;
            exit(0);
        }
        for (auto &u : g[v]) {
            if (u == p) continue;
            if (mn != LLONG_MAX) {
                a[u] = s[u] - s[v];
            }
            dfs(u, v);
        }
    };
    a[1] = s[1];
    dfs(1, 0);
    cout << accumulate(all(a), 0ll);
    return 0;
}
