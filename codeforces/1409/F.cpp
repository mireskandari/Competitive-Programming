#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a) 0
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
}
using namespace Util;

long Calc(long x) {
    return (x * (x - 1)) / 2;
}

void Chmax(long &a, long b) {
    a = a > b ? a : b;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    long n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    if (t[0] == t[1]) {
        cout << Calc(min(n, count(all(s), t[0]) + k));
        exit(0);
    }
    vector<vector<long>> dp(k + 1, vector<long>(n + 1, INT_MIN / 3));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        vector<vector<long>> new_dp(k + 1, vector<long>(n + 1, INT_MIN / 3));
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x <= n; ++x) {
                new_dp[j][x] = dp[j][x];
                
                if (j > 0 && x > 0) Chmax(new_dp[j][x], dp[j - 1][x - 1]);
                if (x > 0 && s[i - 1] == t[0]) Chmax(new_dp[j][x], dp[j][x - 1]);

                if (j > 0 && dp[j - 1][x] > INT_MIN / 3) {
                    Chmax(new_dp[j][x], dp[j - 1][x] + x);
                }
                if (s[i - 1] == t[1] && dp[j][x] > INT_MIN / 3) {
                    Chmax(new_dp[j][x], dp[j][x] + x);
                }
            }
        }
        swap(dp, new_dp);
    }
    cout << *max_element(all(dp[k])) << '\n';
    return 0;
}
