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
#define X first
#define Y second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define forrn(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;
        vector<pii> in(n);
        forn (0, n, i) {
            cin >> in[i].X;
            in[i].Y = i;
        }
        sort(all(in));
        // forn (0, n, i) cout << in[i].X << ' ';
        // cout << '\n';
        vector<pii> ssubs;
        int l = 0, r = 0;
        forn (1, n, i) {
            if (in[i].Y > in[i - 1].Y) {
                if (in[i].X > in[i - 1].X)
                    r++;
            } else {
                ssubs.emplace_back(l, r);
                l = r = i;
            }
        }
        ssubs.emplace_back(l, r);

        ll cnt = 0;
        forn (0, ssubs.size(), i) {
            auto [x, y] = ssubs[i];
            // cout << x << ' ' << y << '\n';
            // if(i >= n) break;
            cnt += y - x + 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX