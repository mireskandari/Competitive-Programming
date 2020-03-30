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
    vector<pair<pair<int, int>, int>> a(n);
    rep (0, n, i) {
        cin >> a[i].X.X >> a[i].X.Y;
        a[i].Y = i;
    }
    stable_sort(all(a));
    rep (0, n, i) {
        if (i != 0) {
            auto it = lower_bound(a.begin(), a.begin() + i - 1, make_pair(make_pair(a[i].X.X, -INT_MAX), -INT_MAX));
            //        cerr << it->X.X << ' ' << it->X.Y << '\n';
            if (it != a.end() && it->X.Y <= a[i].X.Y && it->X.X <= a[i].X.Y && it->X.X >= a[i].X.X) {
                return cout << it->Y + 1 << ' ' << a[i].Y + 1, 0;
            }
        }
        auto it = lower_bound(i + 1 + all(a), make_pair(make_pair(a[i].X.X + 1, -INT_MAX), -INT_MAX));
        if (it != a.end() && it->X.Y <= a[i].X.Y && it->X.X <= a[i].X.Y) {
            return cout << it->Y + 1 << ' ' << a[i].Y + 1, 0;
        }
    }
    cout << -1 << ' ' << -1;
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX
//XXXX DON'T USE IOSTREAM AND STDIO SIMULTANEOUSLY XXXX