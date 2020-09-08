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
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        vector<ll> p(m);
        for (auto &i : p) cin >> i;

        vector<array<ll, 2>> edge(m);
        vector<vector<ll>> g(n);
        for (int i = 0; i < m; ++i) {
            ll v, u;
            cin >> v >> u;
            --v; --u;
            edge[i] = {v, u};
            g[v].emplace_back(i);
            g[u].emplace_back(i);
        }
        
        ll constexpr INF = (ll) 1e14;
        auto bfs = [&](int v) {
            vector<ll> dist(n, INF);
            dist[v] = 0;
            
            queue<ll> q;
            q.emplace(v);
            while (!q.empty()) {
                v = q.front();
                q.pop();
                for (auto &idx : g[v]) {
                    int u = edge[idx][0] + edge[idx][1] - v;
                    if (dist[u] >= INF) {
                        dist[u] = dist[v] + 1;
                        q.emplace(u);
                    } else if (dist[v] + 1 < dist[u]) {
                        dist[u] = dist[v] + 1;
                    }
                }
            }
            return dist;
        };

        auto dist_a = bfs(--a);
        auto dist_b = bfs(--b);
        auto dist_c = bfs(--c);
        
        sort(all(p));
        
        vector<ll> pref(m + 1);
        for (int i = 1; i <= m; ++i) {
            pref[i] = pref[i - 1] + p[i - 1];
        }
        
        ll best = INF;
        for (int i = 0; i < n; ++i) {
            if (dist_a[i] + dist_b[i] + dist_c[i] > m) continue;
            best = min(best, pref[dist_b[i]] + pref[dist_a[i] + dist_b[i] + dist_c[i]]);
        }

        cout << best << '\n';
    }
    return 0;
}
