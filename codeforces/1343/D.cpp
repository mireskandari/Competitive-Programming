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
    
    auto Solve = []() {
        ll n, k;
        cin >> n >> k;
        vector<ll> in(n);
        rep (0, n, i) cin >> in[i];
        vector<ll> cntcan(2 * k + 1, 0), diffcnt(2 * k + 2, 0);
        auto Update = [&](ll l, ll r, ll x) {
            diffcnt[l] += x;
            diffcnt[r + 1] -= x;
        };
        rep (0, n / 2, i) {
            ll sum = in[i] + in[n - i - 1];
            ll mn = sum - max(in[i], in[n - i - 1]) + 1;
            ll mx = sum + (k - min(in[i], in[n - i - 1]));
            Update(max(1LL, mn), max(sum, 1LL), 1);
            Update(min(sum, 2 * k), min(2 * k, mx), 1);
        }
        cntcan[1] = diffcnt[1];
        rep (2, 2 * k + 1, i) {
            cntcan[i] = cntcan[i - 1] + diffcnt[i];
        }
        ll best = max_element(all(cntcan)) - cntcan.begin();
        ll cnt = 0;
        rep (0, n / 2, i) {
            ll sum = in[i] + in[n - i - 1];
            if (sum < best) {
                cnt++;
                if (sum + (k - min(in[i], in[n - i - 1])) < best) cnt++;
            } else if (sum > best) {
                cnt++;
                if (sum - max(in[i], in[n - i - 1]) + 1 > best) cnt++;
            }
        }
        cout << cnt << '\n';
    };
    int tc;
    cin >> tc;
    while (tc--) {
        Solve();
    }
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX