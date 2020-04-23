#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
        ll n, l, r, sum = 0, nl, nr, ldiff;
        cin >> n >> l >> r;
        repr (n - 1, 1, i) {
            if (sum < l && l <= sum + (i * 2) + (i == 1)) {
                nl = i;
                ldiff = l - sum;
                break;
            }
            sum += i * 2 + (i == 1);
        }
        repr (nl, 1, i) {
            if (sum < r && r <= sum + (i * 2) + (i == 1)) {
                nr = i;
                break;
            }
            sum += i * 2 + (i == 1);
        }
        vector<ll> cycle;
        repr (nl, nr, i) {
            ll now = n - i;
            rep (now + 1, n + 1, j) {
                cycle.push_back(now);
                cycle.push_back(j);
            }
        }
        if (nr == 1) cycle.push_back(1);
        int i = ldiff - 1, j = r - l + 1;
        rep (0, j, __) {
            cout << cycle[i++] << ' ';
        }
        cout << '\n';
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