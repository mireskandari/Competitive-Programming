#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 2 * 1e5 + 10;
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e13;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m;

    vector<int> pol;
    auto g = new vector<int>[n];
    auto p = new set<int>[n];
    auto mk = new bool[n];
    auto dist = new ll[n];

    fill(mk, mk + n, false);
    fill(dist, dist + n, INF);
    rep (0, m, i) {
        int u, v;
        cin >> v >> u;
        g[--u].push_back(--v);
    }
    cin >> k;
    rep (0, k, i) {
        int v;
        cin >> v;
        pol.push_back(--v);
    }
    function<void(int v)> bfs = [&](int v) {
        mk[v] = true;
        queue<int> q;
        q.push(v);
        dist[v] = 0;

        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (auto u : g[v]) {
                if (!mk[u]) {
                    dist[u] = dist[v] + 1;
                    p[u].insert(v);
                    q.push(u);
                    mk[u] = true;
                }
                else if (dist[v] + 1 == dist[u]) {
                    p[u].insert(v);
                }
            }
        }
    };
    bfs(pol[k - 1]);
    ll cntmn = 0, cntmx = 0;

    rep (1, k, i) {
        if (p[pol[i - 1]].count(pol[i])) {
            if (p[pol[i - 1]].size() > 1) cntmx++;
        } else {
            cntmn++;
            cntmx++;
        }
    }
    cout << cntmn << ' ' << cntmx;
    return 0;
}