#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int c, m, x;
        cin >> c >> m >> x;
        ll sum = c + m + x;
        int cntm = min({c, m, x});
        sum -= 3 * cntm;
        c -= cntm;
        m -= cntm;
        x -= cntm;
        if (c == 0 || m == 0) cout << cntm << '\n';
        else cout << cntm + (sum / 3 > min(c, m) ? min(c, m) : sum / 3) << '\n';

    }
    return 0;
}