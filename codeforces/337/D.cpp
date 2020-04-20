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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m, d;
    cin >> n >> m >> d;
    vector<char> sp(n, false), mark(n, false);
    auto g = new vector<int>[n];
    rep (0, m, i) {
        int v;
        cin >> v;
        sp[--v] = true;
    }
    rep (0, n - 1, i) {
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    auto change_max = [](auto& f, auto& s, pair<int, int> a) {
        if (a.X > f.X) {
            s = f;
            f = a;
        } else if (a.X > s.X) {
            s = a;
        }
    };
    vector<vector<pair<int, int>>> dp1(n);
    dp1.assign(n, {{-INF, -1}, {-INF, -1}});
    function<void(int)> Dfs1 = [&](int v) {
        mark[v] = true;
        if (sp[v]) change_max(dp1[v][0], dp1[v][1], {0, v});
        for (auto u : g[v]) {
            if (!mark[u]) {
                Dfs1(u);
                auto cand = dp1[u][0];
                cand.X++;
                if (cand.X - 1 != INF) change_max(dp1[v][0], dp1[v][1], cand);
            }
        }
    };
    Dfs1(0);

    fill(all(mark), false);
    vector<int> dp2(n, -INF);
    function<void(int)> Dfs2 = [&](int v) {
        mark[v] = true;
        for (auto u : g[v]) {
            if (!mark[u]) {
                int br = dp1[v][0].Y == dp1[u][0].Y ? 1 : 0;
                dp2[u] = max({dp2[u], dp2[v] + 1, dp1[v][br].X + 1});
                Dfs2(u);
            }
        }
    };
    Dfs2(0);

    int cnt = 0;
    rep (0, n, i) if (max(dp1[i][0].X, dp2[i]) <= d) cnt++;
    cout << cnt;
    return 0;
}