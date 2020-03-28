#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int n, m, k;
vector<int> g[N];
bool mark[N];
int dep[N], pa[N];

vector<int> dfs(int v, int d, int p) {
    mark[v] = true;
    dep[v] = d;
    pa[v] = p;
//    cerr << v << ' ' << dep[v] << '\n';
    for (auto u : g[v]) {
        if (!mark[u]) {
            auto vec = dfs(u, d + 1, v);
            if (vec[0] != -1) return vec;
        }
        else if (dep[v] - dep[u] >= k) {
            int vv = v;
            vector<int> res = {v};
            while (vv != u) {
                vv = pa[vv];
                res.push_back(vv);
            }
            return res;
        }
    }
    return {-1};
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    rep (0, m, i) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    auto res = dfs(0, 0, -1);
    cout << res.size() << '\n';
    for (auto v : res) {
        cout << v + 1 << ' ';
    }
    return 0;
}