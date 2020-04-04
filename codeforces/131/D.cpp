#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 3 * 1e3;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int n, dep[N], par[N];
ll dist[N];
vector<int> g[N], cycle;
bool mark[N];

void dfs(int v, int d, int p) {
    mark[v] = true;
    dep[v] = d;
    par[v] = p;
    for (auto u : g[v]) {
        if (!mark[u]) {
            dfs(u, d + 1, v);
            if (!cycle.empty()) return;
        }
        else if (dep[v] - dep[u] > 1) {
            while (v != u) {
                cycle.push_back(v);
                v = par[v];
            }
            cycle.push_back(u);
            return;
        }
    }
}
void bfs(vector<int> vs) {
    queue<int> q;
    for (auto v : vs) {
        q.push(v);
        dist[v] = 0;
        mark[v] = true;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (!mark[u]) {
                q.push(u);
                dist[u] = min(dist[u], dist[v] + 1);
                mark[u] = true;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    rep (0, n, i) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, 0, -1);
    fill(dist, dist + n, INF);
    fill(mark, mark + n, false);
    bfs(cycle);
    rep (0, n, i) {
        cout << dist[i] << ' ';
    }
    return 0;
}