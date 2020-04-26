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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        ll a, m;
        cin >> a >> m;
        ll b = __gcd(a, m);
        auto Phi = [](ll n) {
            ll res = n;
            for (ll p = 2; p * p <= n; p++) {
                if (n % p == 0) {
                    while (n % p == 0) n /= p;
                    res -= res / p;
                }
            }
            if (n > 1) res -= res / n;
            return res;
        };
        cout << Phi(m / b) << '\n';
    }
    return 0;
}