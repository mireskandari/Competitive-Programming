#include <bits/stdc++.h>
using namespace std;

int dp[101][101][11][11];
int constexpr MOD = 1e8;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nnn, nn, kkk, kk;
    cin >> nnn >> nn >> kkk >> kk;
    for (int nf = 0; nf <= nnn; nf++) {
        for (int nk = 0; nk <= nn; nk++) {
            for (int kf = 0; kf <= kkk; kf++) {
                for (int kh = 0; kh <= kk; kh++) {
                    long long ans = 0;
                    if (nf + nk == 0) ans = 1;
                    else {
                        if (nf > 0 && kf > 0) ans += dp[nf - 1][nk][kf - 1][kk] % MOD;
                        ans %= MOD;
                        if (nk > 0 && kh > 0) ans += dp[nf][nk - 1][kkk][kh - 1] % MOD;
                        ans %= MOD;
                    }
                    dp[nf][nk][kf][kh] = ans;
//                    cerr << nf << ' ' << nk << ' ' << kf << ' ' << kh << ' ' << ans << '\n';
                }
            }
        }
    }
    cout << dp[nnn][nn][kkk][kk];
    return 0;
}