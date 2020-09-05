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

void Chmin(long &a, long b) {
    a = a > b ? b : a;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    long n, x, y; cin >> n >> x >> y;
    vector<long> dp(n + 1);
    dp[0] = 0; dp[1] = x;
    for (int i = 2; i <= n; ++i) {
        if (i & 1) {
            dp[i] = dp[(i + 1) >> 1] + x + y;
        } else {
            dp[i] = dp[i >> 1] + y;
        }
        Chmin(dp[i], dp[i - 1] + x);
    }
    cout << dp[n];
    return 0;
}