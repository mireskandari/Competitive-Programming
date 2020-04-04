//
// Created by mrskndri on 4/4/20.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 5 * 1e4;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int n, par[N];
vector<int> g[N];
bool mark[N];

void dfs(int v, int p) {
    mark[v] = true;
    par[v] = p;
    for (auto u : g[v]) {
        if (!mark[u]) {
            dfs(u, v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int r1, r2;
    cin >> n >> r1 >> r2;
    r1--; r2--;
    rep (0, n, i) {
        if (i == r1) continue;
        int v;
        cin >> v;
        v--;
        g[v].push_back(i);
        g[i].push_back(v);
    }
    dfs(r2, -1);
    rep (0, n, i) {
        if (i == r2) continue;
        cout << par[i] + 1 << ' ';
    }
    return 0;
}
