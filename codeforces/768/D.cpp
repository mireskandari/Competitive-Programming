#include <bits/stdc++.h>
using namespace std;
const int _R = [] { ios::sync_with_stdio(false), cin.tie(nullptr); return 1; }();
#ifdef LOCAL
#define dbg(a) cerr << "\"" << #a << "\"=" << a << '\n'
#else
#define dbg(a) 0
#endif

constexpr int N = 10000, K = 1010;

double dp[N][K];

signed main() {
    cerr << fixed << setprecision(6);
    int k, q;
    cin >> k >> q;
    dp[0][0] = 1.0;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j - 1] * (double(k - j + 1) / double(k)) + (double(j) / double(k)) * dp[i - 1][j];
        }
    }
    while (q--) {
        int p;
        cin >> p;
        double prob = double(p);
        prob /= 2000.0;
        for (int i = 1; i < N; ++i) {
            dbg(i); dbg(dp[i][k]);
            if (dp[i][k] >= prob) {
                cout << i << '\n';
                break;
            }
        }
        dbg("-----");
    }
    return 0;
}
