#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int const N = 1e5;
ll const INF = 1e18;
int n, m, k;
ll dist[N];
vector<pair<int, int>> adj[N];
vector<int> bks;

void spath() {
    set<pair<ll, int>> q;
    forn(0, n, i) {
        q.insert(make_pair(dist[i], i));
    }
    while(!q.empty()) {
        int v = q.begin()->S;
        q.erase(q.begin());
        for(auto u : adj[v]) {
            if(dist[u.F] > dist[v] + u.S) {
                q.erase(q.find(make_pair(dist[u.F], u.F)));
                dist[u.F] = dist[v] + u.S;
                q.insert(make_pair(dist[u.F], u.F));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    fill(dist, dist + n, INF);
    forn(0, m, i) {
        int v, u, l;
        cin >> v >> u >> l;
        v--; u--;
        adj[v].push_back(make_pair(u, l));
        adj[u].push_back(make_pair(v, l));
    }
    forn(0, k, i) {
        int b;
        cin >> b;
        b--;
        bks.push_back(b);
        dist[b] = 0;
    }
    spath();
    ll best = INF;
    forn(0, n, i) {
        if(dist[i] != 0 && dist[i] < best) best = dist[i];
    }
    cout << (best >= INF ? -1 : best);
    return 0;
}