#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 10;
int c[10];
int dp[N];
int best[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++) cin >> c[i];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        best[i] = 0;
        for (int j = 1; j <= 9; j++) {
            if (i - c[j] >= 0 && dp[i] <= dp[i - c[j]] + 1) {
                dp[i] = dp[i - c[j]] + 1;
                best[i] = j;
            }
        }
    }
    if (dp[n] == 0) {
        cout << -1 << '\n';
        return 0;
    }
    string s;
    int i = n;
    while (i > 0 && best[i] > 0) {
        s += char(best[i] + '0');
        i -= c[best[i]];
    }
    cout << s;
    return 0;
}