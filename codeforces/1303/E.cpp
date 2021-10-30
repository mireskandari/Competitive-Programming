#include <bits/stdc++.h>
using namespace std;

#define show(a) #a << ' ' << a << "    "

constexpr int N = 500;

char s[N], t[N];
int dp[N][N];
vector<int> pos[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int tc;
    cin >> tc;
    while (tc--) {
        fill_n(pos, 30, vector<int>());

        cin >> (s + 1) >> (t + 1);
        int n = (int) strlen(s + 1), m = (int) strlen(t + 1);
        
        for (int i = 1; i <= m; ++i) {
            pos[t[i] - 'a'].push_back(i);
        }
        
        bool found = false;
        for (int i = 1; i <= m; ++i) {
            memset(dp, -1, sizeof(dp));

            // dp[j][k] = s[j] == s[k] -> dp[j - 1][k - 1]
            //   t.next(dp[j - 1][k], s[j]) == dp[j - 1][k] + 1 -> dp[j - 1][k] + 1
            
            dp[0][0] = i - 1;
            for (int j = 1; j <= n; ++j) {
                for (int k = 0; k <= i; ++k) {
                    dp[j][k] = dp[j - 1][k];
                    if (k > 0 && s[j] == t[k])
                        dp[j][k] = max(dp[j][k], dp[j - 1][k - 1]);
                    if (dp[j - 1][k] == -1) {
                        continue;
                    }
                    auto p = lower_bound(begin(pos[s[j] - 'a']), end(pos[s[j] - 'a']), dp[j - 1][k] + 1);
                    if (p == end(pos[s[j] - 'a'])) {
                        continue;
                    }
                    if (*p == dp[j - 1][k] + 1)
                        dp[j][k] = max(dp[j][k], dp[j - 1][k] + 1);
                }
            } 
            if (dp[n][i - 1] == m) {
                found = true;
                break;
            }
        }
        
        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}