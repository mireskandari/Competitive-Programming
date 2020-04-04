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
#define acm_input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define Mp make_pair
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define debug(...) cerr<<"[ "<<#__VA_ARGS__<<" ]: ";debug_out(__VA_ARGS__)
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<'\n'
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<'\n'
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<'\n'

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;
ll phi[N + 1], cnt;
vector<pii> edge;
bool mk[N + 1];
map<pii, bool> mark;
int nn, m;
void dfs(int v) {
    mk[v] = true;
    repr (v - 1, 1, i) {
//        cerr << __gcd(v, int(i)) << '\n';
        if (!mark[{v, i}] && !mark[{i, v}] && __gcd(v, int(i)) == 1) {
            edge.emplace_back(v, i);
            cnt++;
            mark[{v, i}] = true;
            mark[{i, v}] = true;
            if (cnt == m) return;
            if (!mk[i]) dfs(i);
            if (cnt == m) return;
        }
    }
}
void totient(int n) {
    for (int i=1; i<=n; i++)
        phi[i] = i;

    for (int p=2; p<=n; p++) {
        if (phi[p] == p) {
            phi[p] = p-1;
            for (int i = 2*p; i<=n; i += p) {
                phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> nn >> m;
    totient(nn);
    vector<ll> pt(nn + 1);
    partial_sum(phi + 1, phi + nn + 1, pt.begin() + 1);
    cerr << pt[nn] - 1 << ' ';

    if (nn - 1 > m || pt[nn] - 1 < m) return cout << "Impossible", 0;
    cout << "Possible\n";

    dfs(nn);
    for (auto e : edge) {
        cout << e.X << ' ' << e.Y << '\n';
    }
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX//
// Created by mrskndri on 4/4/20.
//

