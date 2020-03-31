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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int> q(n - 1), sq(n - 1);
    rep (0, n - 1, i) cin >> q[i];
    partial_sum(all(q), sq.begin());
    int mn = *min_element(all(sq));
    int mx = *max_element(all(sq));
    int f;
    vector<int> pp(n);
    iota(all(pp), 1);
    if (mn > 0 || mx < 0) {
        if (mn > 0) f = 1;
        if (mx < 0) f = n;
        vector<int> p(n);
        p[0] = f;
        rep (1, n, i) p[i] = p[i - 1] + q[i - 1];
        sort(all(p));
        if (p != pp) return cout << -1, 0;
    }
    else {
        if (n - mx != 1 + -mn) return cout << -1, 0;
        f = n - mx;
        vector<int> p(n);
        p[0] = f;
        rep (1, n, i) p[i] = p[i - 1] + q[i - 1];
        sort(all(p));
        if (p != pp) return cout << -1, 0;
    }

    cout << f << ' ';
    rep (0, n - 1, i) {
        cout << f + sq[i] << ' ';
    }
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX