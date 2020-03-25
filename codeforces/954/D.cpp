#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << H << ' '; debug_out(T...); }
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
typedef string str;
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define debug(...) cerr<<"[ "<<#__VA_ARGS__<<" ]: "<<debug_out(__VA_ARGS__)
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl

int constexpr N = 1e3;
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e13;

vector<int> g[N];
bool adj[N][N];
vector<char> mark;
ll dist[N][2];

void bfs(int v, int x) {
    mark[v] = true;
    dist[v][x] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (!mark[u]) {
                dist[u][x] = min(dist[u][x], dist[v][x] + 1);
                mark[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    fill(&dist[0][0], &dist[n - 1][1] + 1, INF);
    mark.resize(n);
    rep (0, m, i) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
        adj[v][u] = adj[u][v] = true;
    }
    bfs(s, 0);
    mark.assign(n, false);
    
    bfs(t, 1);
    ll cnt = 0;
    rep (0, n, i) {
        rep (i + 1, n, j) {

            if (!adj[i][j]) {
                if (dist[t][0] <= min(dist[i][0] + dist[j][1] + 1, dist[j][0] + dist[i][1] + 1)) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX