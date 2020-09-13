#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(a) cerr << "\"" << #a << "\"=" << a << '\n'
#else
#define dbg(a) 0
#endif

int64_t constexpr INF = int64_t(1e14);

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, s, k;
    cin >> n >> m >> k >> s;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
        --i;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    auto bfs = [&](vector<int> st) -> vector<int64_t> {
        vector<int64_t> dist(n, INF);
        queue<int> q;
        for (auto &v : st) {
            dist[v] = 0;
            q.emplace(v);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &u : g[v]) {
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
    vector<vector<int>> vk(k);
    for (int i = 0; i < n; ++i) {
        vk[a[i]].emplace_back(i);
    }
    vector<vector<int64_t>> dists(k);
    for (int i = 0; i < k; ++i) {
        dists[i] = bfs(vk[i]);
    }
    for (int i = 0; i < n; ++i) {
        priority_queue<int64_t> pq;
        for (int j = 0; j < k; ++j) {
            pq.emplace(dists[j][i]);
        }
        while (int(pq.size()) > s) pq.pop();
        int64_t ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        cout << ans << ' ';
    }
    return 0;
}

