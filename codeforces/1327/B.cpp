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
        vector<int> a(n, -1);
        vector<char> used(n, 0);
        rep (0, n, i) {
            int k;
            cin >> k;
            int b;
            rep (0, k, j) {
                cin >> b;
                if (a[i] != -1) continue;
                else if (!used[b - 1]) {
                    a[i] = b - 1;
                    used[b - 1] = true;
                }
            }
        }
        int ed = -1;
        rep (0, n, i) {
            if (a[i] == -1) ed = i + 1;
        }
        int ek = -1;
        rep (0, n, i) {
            if (!used[i]) ek = i + 1;
        }
        if (ek == -1 || ed == -1) cout << "OPTIMAL\n";
        else cout << "IMPROVE\n" << ed << ' ' << ek << '\n';
    }

    return 0;
}

//XXXX CHECK FOR SHTTY OVERFLOWS XXXX