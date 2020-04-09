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

vector<int> g[500];
vector<int> cycle;
int mark[500], par[500];
bool found;

void dfs1(int v, int p) {
    mark[v] = 1;
    par[v] = p;

    for (auto u : g[v]) {
        if (mark[u] == 0) {
            dfs1(u, v);
            if (found) return;
        }
        else if (mark[u] == 1) {
            while (v != u) {
                cycle.push_back(v);
                v = par[v];
            }
            cycle.push_back(u);
            found = true;
            return;
        }
    }
    mark[v] = 2;
}

void dfs2(int v, pair<int, int> now) {
    mark[v] = 1;
    for (auto u : g[v]) {
        if (now != pair<int, int>(v, u)) {
            if (mark[u] == 0) {
                dfs2(u, now);
                if (found) return;
            } else if (mark[u] == 1) {
                found = true;
                return;
            }
        }
    }
    mark[v] = 2;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    rep (0, m, i) {
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
    }
    rep (0, n, i) {
        if (mark[i] == 0 && !found) {
            dfs1(i, -1);
        }
    }
    if (!found) return cout << "YES", 0;
    reverse(all(cycle));
    cycle.push_back(cycle[0]);

    rep (0, cycle.size() - 1, i) {
        found = false;
        fill(mark, mark + n, 0);
        pair<int, int> edge(cycle[i], cycle[i + 1]);
        rep (0, n, j) {
            if (mark[j] == 0 && !found) {
                dfs2(j, edge);
            }
        }

        if (!found) return cout << "YES", 0;
    }
    cout << "NO";
    return 0;
}