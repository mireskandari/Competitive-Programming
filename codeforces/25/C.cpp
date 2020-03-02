#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 300;

int n, k, dist[N][N];
vector<pair<int, int>> adj[N];
vector<pair<int, pair<int, int>>> rds;
ll sum;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    forn(0, n, i) {
        forn(0, n, j) {
            cin >> dist[i][j];
        }
    }
    cin >> k;
    forn(0, k, i) {
        int u, v, l;
        cin >> u >> v >> l;
        v--; u--;
        rds.push_back(make_pair(l, make_pair(v, u)));
    }
    for(auto rd : rds) {
        int v = rd.SV.FV, u = rd.SV.SV, l = rd.FV;
        sum = 0;
        forn(0, n, i) {
            forn(0, n, j) {
                dist[i][j] = min(dist[i][j],
                                 min(dist[i][v] + l + dist[u][j],
                                     dist[j][v] + l + dist[u][i]));
                sum += dist[i][j];
            }
        }
        cout << sum / 2 << ' ';
    }
    return 0;
}