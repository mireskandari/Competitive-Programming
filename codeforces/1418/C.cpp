#include <bits/stdc++.h>
using namespace std;
const auto _R = [] { ios::sync_with_stdio(0); return cin.tie(0); }();
#ifdef LOCAL
#define dbg(a) cerr << "\"" << #a << "\"=" << a << '\n'
#else
#define dbg(a) 0
#endif

constexpr int N = int(2.1e5);

int a[N], dp[N][2];

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        memset(dp, 0x3f, sizeof(dp));
        // 1 : you, 0: friend
        dp[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][1] + a[i];
            if (i - 2 >= 0) dp[i][0] = min(dp[i][0], dp[i - 2][1] + a[i - 1] + a[i]);
            dp[i][1] = dp[i - 1][0];
            if (i - 2 >= 0) dp[i][1] = min(dp[i][1], dp[i - 2][0]);
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
    return 0;
}
