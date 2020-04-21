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
        ll n, m;
        cin >> n >> m;
        ll zl = (n - m + 1) / 2, zr = (n - m) / 2;
        if (m == 0) cout << 0 << '\n';
        else if (n - m > m) {
            ll af = n - m;
            ll lz = af / (m + 1);
            ll rm = af % (m + 1);
            cout << (n * (n + 1) / 2) - (m - rm + 1) * (lz * (lz + 1) / 2) - rm * ((lz + 1) * (lz + 2) / 2) << '\n';
        } else {
            cout << (n * (n + 1) / 2) - (n - m) << '\n';
        }
    }
    return 0;
}