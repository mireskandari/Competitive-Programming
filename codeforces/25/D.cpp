#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e3;

int n, p[N];
vector<int> adj[N], root;
bool mark[N], mark2[N][N];
vector<pair<int, int>> cycle;

void dfs(int v) {
    mark[v] = true;
    for(auto u : adj[v]) {
        if(!mark[u]) {
            p[u] = v;
            dfs(u);
        }
        else if(p[v] != u && !mark2[v][u]) {
            cycle.push_back(make_pair(v, u));
            mark2[v][u] = mark2[u][v] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    forn(0, n - 1, i) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    forn(0, n, i) {
        if(!mark[i]) {
            p[i] = -1;
            root.push_back(i);
            dfs(i);
        }
    }
    cout << cycle.size() << '\n';
    forn(0, cycle.size(), i) {
        cout << cycle[i].F + 1 << ' ' << cycle[i].S + 1 << ' ' << root[i] + 1 << ' ' << root[i + 1] + 1 << '\n';
    }
    return 0;
}