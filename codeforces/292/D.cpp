#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
typedef string str;
#define all(x) (x).begin(),(x).end()
#define FV first
#define SV second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define forrn(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;

int constexpr N = 502;

vector<vector<pii>> adj;
vector<pii> ex;
array<bool, N> mark;


void dfs(int v, int k) {
    mark[v] = true;
    // cout << v << ' ';
    for (auto u : adj[v]) {
        if (!(ex[k].FV <= u.SV && u.SV <= ex[k].SV) &&
            !mark[u.FV]) {

            dfs(u.FV, k);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m, k;
    cin >> n >> m;
    adj.resize(n);

    forn (0, m, i) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        adj[v].emplace_back(u, i);
        adj[u].emplace_back(v, i);
    }
    cin >> k;
    forn (0, k, i) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        ex.emplace_back(l, r);
        
        mark.fill(false);
        int cnt = 0;
        forn (0, n, j) {
            if (!mark[j]) {
                dfs(j, i);
                cnt++;
                // cout << '\n';
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}