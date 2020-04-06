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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep (0, n, i) cin >> a[i];
    ll g = a[0];
    rep (1, n, i) {
        g = __gcd(a[i], g);

    }
    ll cnt = 0;
    for (long long i = 1; i * i <= g; i++) {
        if (g % i == 0) {
//            cerr << i << '\n';
            if (i * i != g) cnt += 2;
            else cnt++;
        }
    }
    cout << cnt;
    return 0;
}