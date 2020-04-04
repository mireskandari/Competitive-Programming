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

int n, m, sq;
vector<int> g[N];
bool mark[N], inmark[N];
int dep[N], par[N];
vector<int> cycle, inset;

void dfs(int v, int d, int p) {
    mark[v] = true;
    dep[v] = d;
    par[v] = p;
    int cntb = 0, lastb = INT_MAX;
//    vector<int> b;
    for (auto u : g[v]) {
        if (mark[u]) {
            cntb++;
            if (lastb == INT_MAX || dep[u] < dep[lastb]) lastb = u;
        }
    }
    for (auto u : g[v]) {
        if (!mark[u]) {
            dfs(u, d + 1, v);
            if (!cycle.empty() || inset.size() == sq) return;
        }
    }
//    cerr << v + 1 << ' ' << cntb << '\n';
    if (cntb < sq - 1 && !inmark[v]) {
        inset.push_back(v);
        inmark[v] = true;

        for (auto u : g[v]) inmark[u] = true;
        if (inset.size() == sq) return;
    }
    else if (cntb >= sq - 1) {
//        cerr << v + 1 << ' ' << "cntb: " << cntb << ' ' << "p: " << par[v] << '\n';
//        for (auto u : b) cerr << u + 1<< ' ';
        while (v != lastb) {
            cycle.push_back(v);
            v = par[v];
        }
        cycle.push_back(lastb);
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    sq = ceil(sqrt(n));
//    cout << sq << '\n';
    rep (0, m, i) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, 0, -1);
//    cout << '\n';
    if (!cycle.empty()) {
        cout << "2\n" << cycle.size() << '\n';
        for (auto v : cycle) {
            cout << v + 1 << ' ';
        }
    } else {
        cout << "1\n";
//        cerr << inset.size() << '\n';
        for (auto v : inset) {
            cout << v + 1 << ' ';
        }
    }
    return 0;
}