#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void debug_out() { cerr << '\n'; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        ll a, b, q;
        cin >> a >> b >> q;
        while (q--) {
            ll l, r;
            cin >> l >> r;
            ll cnta = 0, cntb = 0, cntab = 0;
            rep (0, max(a, b), i) {
                auto Solve = [](ll l, ll r, ll a, ll& cnta, ll i) {
                    if (i >= a) return;
                    ll la = l, ra = r;
                    if (la % a > i) {
                        la += a;
                        la -= la % a - i;
                    }
                    else {
                        la += i - la % a;
                    }
                    if (ra % a > i) ra -= ra % a - i;
                    else {
                        ra -= i;
                        ra += i - ra % a;
                    }
                    if (ra < la || la > r || ra < l) cnta += 0;
                    else {
                        cnta += (ra - la) / a + 1;
                    }
                };
                Solve(l, r, a, cnta, i);
                Solve(l, r, b, cntb, i);
                Solve(l, r, a * b / __gcd(a, b), cntab, i);
            }
            cout << -((r - l + 1) - cnta - cntb + cntab) << ' ';
        }
        cout << '\n';
    }
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX