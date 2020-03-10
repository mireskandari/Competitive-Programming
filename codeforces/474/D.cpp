#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

ll dp[N + 1], sum[N + 1];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc, k;
    cin >> tc >> k;
    forn (0, k, i) dp[i] = 1;
    forn (k, N + 1, i) {
        dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
    }
    partial_sum(dp, dp + N + 1, sum);
    
    while (tc--) {
        int a, b;
        cin >> a >> b;
        cout << (sum[b] - sum[a - 1]) % MOD << '\n';
    }
    return 0;
}