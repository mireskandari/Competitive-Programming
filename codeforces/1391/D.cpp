#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
#define dbg(a) 0
// #define dbg(a) cerr << "\"" << #a << "\":" << a << '\n'

#define int ll

inline int bit(int a, int i) {
    return (a >> i) & 1;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            a[i][j] = c == '1';
        }
    }
    if (n > 3) {
        cout << -1;
        exit(0);
    }
    vector<vector<int>> trans(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            bool ok = true;
            for (int x = 1; x < n; ++x) {
                if ((bit(i, x) + bit(i, x - 1) + bit(j, x) + bit(j, x - 1)) % 2 == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) trans[i].emplace_back(j);
        }
    }
    vector<vector<int>> dp(1 << n, vector<int>(m + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            int cost = 0;
            for (int x = 0; x < n; ++x) {
                if (bit(j, x) != a[x][i - 1]) cost++; // retarded
            }
            dp[j][i] = 0x3f3f3f3f;
            for (auto &x : trans[j]) {
                dp[j][i] = min(dp[j][i], dp[x][i - 1] + cost);
            }
            dbg(dp[j][i]); dbg(bitset<4>(j).to_string()); dbg(i);
        }
        dbg("----------");
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < (1 << n); ++i) {
        ans = min(ans, dp[i][m]);
    }
    cout << ans;
    return 0;
}
