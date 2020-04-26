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
ll constexpr INF = INT64_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    auto Solve = []() {
        ll n, m;
        cin >> m >> n;
        vector<ll> p(1000, 0);
        ll sum = 0;
        rep (0, n, i) {
            ll a;
            cin >> a;
            sum += a;
            p[log2(a)]++;
        }
        if (sum < m) return cout << "-1\n", 0;
        ll i = 0;
        ll cnt = 0;
        while (i < log2(m) + 1) {
            if ((m >> i) & 1) {
                if (p[i] > 0) {
                    p[i]--;
                } else {
                    ll j = i + 1;
                    while (p[j] < 1) j++;
                    while (j > i) {
                        p[j]--;
                        p[j - 1] += 2;
                        j--;
                        cnt++;
                    }
                    p[i]--;
                }
            }
            p[i + 1] += p[i] / 2;
            i++;
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