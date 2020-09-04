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


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        long n, k; cin >> n >> k;
        vector<long> x(n); for (auto &i : x) cin >> i;
        for (int i = 0; i < n; ++i) {
            long shit; cin >> shit;
        }
        sort(all(x));
        vector<vector<long>> dp(n + 1, vector<long>(3));
        for (int i = 1, j = 1; i <= n; ++i) {
            while (x[i - 1] - x[j - 1] > k) ++j;
            for (int x = 1; x <= 2; ++x) {
                dp[i][x] = max(dp[i - 1][x], i - j + 1 + dp[j - 1][x - 1]);
            }
        }
        cout << dp[n][2] << '\n';
    }
    return 0;
}
