#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int const N = 2e5 + 10;
int n, m;
vector<int> g[N];
using pii = pair<int, int>;
vector<pii> edge;
bool mark[N], marke[N];
int dep[N];

tuple<int, int, int> dfs(int v, tuple<int, int, int> last) {
    mark[v] = true;
    get<0>(last)++;
    for (auto &x : g[v]) {
        if (!marke[x]) {
            get<1>(last)++;
            marke[x] = true;
        }
    }
    for (auto &x : g[v]) {
        int u = edge[x].X == v ? edge[x].Y : edge[x].X;
        if (mark[u] && dep[v] - dep[u] > 1) {
            cerr << dep[v] << ' ' << dep[u] << ' ' << v + 1 << ' ' << u + 1 << '\n';
            get<2>(last) += dep[v] - dep[u] + 1;
        }
    }
    for (auto &x : g[v]) {
        int u = edge[x].X == v ? edge[x].Y : edge[x].X;
        if (!mark[u]) {
            dep[u] = dep[v] + 1;
            auto res = dfs(u, {0, 0, 0});
            get<0>(last) += get<0>(res);
            get<1>(last) += get<1>(res);
            get<2>(last) += get<2>(res);
        }
    }
    return last;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(edge.size());
        g[--u].emplace_back(edge.size());
        edge.emplace_back(v, u);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            tuple<int, int, int> res = dfs(i, {0, 0, 0});
            cerr << get<0>(res) << ' ' << get<1>(res) << ' ' << get<2>(res) << '\n';
            if (get<0>(res) == get<1>(res) && get<0>(res) == get<2>(res)) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}