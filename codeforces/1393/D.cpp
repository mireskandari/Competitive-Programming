#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();

signed main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto in_bound = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    };
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (!in_bound(i - 1, j - 1) || !in_bound(i - 2, j) || !in_bound(i - 1, j + 1) || a[i - 1][j - 1] != a[i][j] || a[i - 2][j] != a[i][j] || a[i - 1][j + 1] != a[i][j] || a[i - 1][j] != a[i][j]) 
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 2][j], dp[i - 1][j + 1]});
        }
    ll ans = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans += dp[i][j];
    cout << ans;
    return 0;
}
