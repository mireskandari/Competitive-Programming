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

int constexpr N = 1e6;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;
ll ri[N], le[N], tmp[N], in[N];

ll solve(int l, int r) {
    if (r - l <= 1) return 0;
    int m = (r + l) / 2;
    ll res = solve(l, m) + solve(m, r);
    int i = l, j = m;
    while (i < m && j < r) {
        if (le[i] > ri[j]) {
            j++;
            res += m - i;
        } else {
            i++;
        }
    }
    merge(le + l, le + m, le + m, le + r, tmp + l);
    rep (l, r, x) le[x] = tmp[x];
    merge (ri + l, ri + m, ri + m, ri + r, tmp + l);
    rep (l, r, x) ri[x] = tmp[x];
    return res;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    rep (0, n, i) cin >> in[i];
    map<int, int> cnt, rcnt;
    rep (0, n, i) {
        le[i] = ++cnt[in[i]];
        ri[n - i - 1] = ++rcnt[in[n - i - 1]];
    }
//    rep (0, n, i) cerr << le[i] << ' ';
//    cerr << '\n';
//    rep (0, n, i) cerr << ri[i] << ' ';
    cout << solve(0, n);
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX