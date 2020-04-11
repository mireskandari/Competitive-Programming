#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8;
int dp[101][101][11][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nn, n, kkk, kk;
    cin >> nn >> n >> kkk >> kk;
    dp[0][0][1][0] = dp[0][0][1][1] = 1;
    for (int n1 = 0; n1 <= nn; n1++) {
        for (int n2 = 0; n2 <= n; n2++) {
            for (int k = 1; k <= max(kkk, kk); k++) {
                if (n1 == 0 && n2 == 0) continue;

                if (k > n1 || k > kkk) dp[n1][n2][k][0] = 0;
                else if (k == 1) {
                    for (int i = 1; i <= kk; i++) {
                        dp[n1][n2][k][0] += dp[n1 - 1][n2][i][1] % MOD;
                        dp[n1][n2][k][0] %= MOD;
                    }
                }
                else dp[n1][n2][k][0] = dp[n1 - 1][n2][k - 1][0];

                if (k > n2 || k > kk) dp[n1][n2][k][1] = 0;
                else if (k == 1) {
                    for (int i = 1; i <= kkk; i++) {
                        dp[n1][n2][k][1] += dp[n1][n2 - 1][i][0] % MOD;
                        dp[n1][n2][k][1] %= MOD;
                    }
                }
                else dp[n1][n2][k][1] = dp[n1][n2 - 1][k - 1][1];
            }
        }
    }
    long long sum = 0;
    for (int k = 1; k <= max(kkk, kk); k++) {
        sum = (sum % MOD + dp[nn][n][k][0] % MOD + dp[nn][n][k][1] % MOD) % MOD;
    }
    cout << sum;
    return 0;
}