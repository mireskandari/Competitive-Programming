#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    vector<bool> col(n, false), mark(n, false);
    auto &&dfs = [&](auto &f, int v) -> bool {
        mark[v] = true;
        for (auto &u : g[v]) {
            if (mark[u] && col[u] == col[v]) return false;
        }
        for (auto &u : g[v]) {
            if (!mark[u]) {
                col[u] = !col[v];
                if (!f(f, u)) return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            col[i] = false;
            if (!dfs(dfs, i)) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << count(all(col), true) << '\n';
    for (int i = 0; i < n; i++) {
        if (col[i]) cout << i + 1 << ' ';
    }
    cout << '\n' << count(all(col), false) << '\n';
    for (int i = 0; i < n; i++) {
        if (!col[i]) cout << i + 1 << ' ';
    }
    return 0;
}