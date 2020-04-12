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

int solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> in(n);
    rep (0, n, i) {
        int t, l, h;
        cin >> t >> l >> h;
        in[i] = {t, l, h};
    }

    ll tt = 0;
    ll mintemp = m, maxtemp = m;
    rep (0, n, i) {
        auto [t, l, h] = in[i];

        ll diff = t - tt;
        if (h >= mintemp - diff && l <= maxtemp + diff) {
            mintemp = max(l, mintemp - diff);
            maxtemp = min(h, maxtemp + diff);
        }
        else return cout << "NO\n", 0;
        tt = t;
    }
    cout << "YES\n";
    return 0;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}