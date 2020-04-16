#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 2 * 1e5;
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e14;

int n, m, k;
ll dist[2][N];
vector<int> g[N];
bool mark[2][N], sp[N];

void bfs(int v, int x) {
    mark[x][v] = true;
    dist[x][v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (!mark[x][u]) {
                dist[x][u] = min(dist[x][u], dist[x][v] + 1);
                mark[x][u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    rep (0, k, i) {
        int v;
        cin >> v;
        sp[--v] = true;
    }
    rep (0, m, i) {
        int u, v;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    fill(&dist[0][0], &dist[1][n - 1] + 1, INF);
    bfs(0, 0);
    bfs(n - 1, 1);

    set<pair<ll, int>, greater<>> choice;
    vector<pair<ll, int>> dist1;
    rep (0, n, i) {
        if (!sp[i]) continue;
        choice.emplace(dist[1][i], i);
        dist1.emplace_back(dist[0][i], i);
    }
    sort(all(dist1));
    ll mx = 0;
    rep (0, k, i) {
        choice.erase(choice.find(make_pair(dist[1][dist1[i].Y], dist1[i].Y)));
        if (!choice.empty()) {
            ll best = choice.begin()->X;
            mx = max(mx, best + dist1[i].X + 1);
        }
    }
    cout << min(dist[0][n - 1], mx);
    return 0;
}
