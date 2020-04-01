#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 5 * 1e3;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

vector<int> g[N];
bool mark[N], adj[N][N];

tuple<int, int, int> dfs(int v, int p) {
    mark[v] = true;
//    cerr << v << ' ' << dep[v] << '\n';
    for (auto u : g[v]) {
        if (p != -1 && adj[u][p]) {
            return {p, v, u};
        }
        if (!mark[u]) {
            int v1, v2, v3;
            tie(v1, v2, v3) = dfs(u, v);
            if (v1 != -1) return {v1, v2, v3};
        }
    }
    return {-1, -1, -1};
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    rep (0, n, i) {
        rep (0, n, j) {
            char c;
            cin >> c;
//            cerr << c << ' ';
            adj[i][j] = c - '0';
            if (c - '0') g[i].push_back(j);
        }
    }
    rep (0, n, i) {
        if (!mark[i]) {
            int v1, v2, v3;
            tie(v1, v2, v3) = dfs(i, -1);
            //    if (v1 == -1) cout << -1;
            if (v1 != -1) return cout << v1 + 1 << ' ' << v2 + 1 << ' ' << v3 + 1, 0;
        }
    }
    cout << -1;
//    else {
//        reverse(all(res));
//        rotate(res.begin(), res.begin() + 1, res.end());
//        deque<int> vs(all(res));
//        int f = res.back(), v = res[1];
//        vs.pop_back();
//        while (vs.size() > 2) {
//            if (adj[f][v]) {
//                while (vs.front() != v) vs.pop_front();
//            } else {
//                while (vs.back() != v) vs.pop_back();
//            }
//            v = vs[0];
//        }
//        for (auto u : vs)
//            cout << u + 1 << ' ';
//        cout << f + 1;
//    }
    return 0;
}