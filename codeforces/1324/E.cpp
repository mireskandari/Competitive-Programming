#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e13;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<ll> a(n), sa(n);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -INF));
    rep (0, n, i) cin >> a[i];
    partial_sum(all(a), sa.begin());
    dp[0][0] = 0;
    rep (0, n, i) {
        rep (0, n + 1, j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (l <= (sa[i] - j) % h && (sa[i] - j) % h <= r));
            if (j < n) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (l <= (sa[i] - j - 1) % h && (sa[i] - j - 1) % h <= r));
        }
    }
    ll best = -INF;
    rep (0, n + 1, i) {
        best = max(dp[n][i], best);
    }
    cout << best;
    return 0;
}