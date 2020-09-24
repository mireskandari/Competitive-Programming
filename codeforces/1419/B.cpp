#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
#define dbg(a) // cerr << __LINE__ << " \"" << #a << "\":" << a << '\n'

ll f(ll n) {
    return (1ll << (n + 1)) - 1;
}
ll g(ll n) {
    return (f(n) * f(n) - f(n)) / 2 + f(n);
}

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll x;
        cin >> x;
        ll i;
        for (i = 0; g(i) <= x; ++i) {
            x -= g(i);
            dbg(x);
        }
        cout << i << '\n';
    }
    return 0;
}
