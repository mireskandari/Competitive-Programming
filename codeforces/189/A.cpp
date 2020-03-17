#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

int constexpr N = 4001;
int constexpr MOD = 1e9 + 7;
int constexpr INF = -1e8;

array<int, N> dp;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    dp.fill(-1);
    dp[0] = 0;
    forn (1, n + 1, i) {
        int aa = (i - a < 0 ? INF : dp[i - a] + 1),
        bb = (i - b < 0 ? INF : dp[i - b] + 1),
        cc = (i - c < 0 ? INF : dp[i - c] + 1);
        dp[i] = max(aa, max(bb, cc));
    }
    cout << dp[n];
    return 0;
}