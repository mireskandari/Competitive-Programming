#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
#define dbg(a) 0
// #define dbg(a) cerr << __LINE__ << " \"" << #a << "\":" << a << '\n'

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll l, r, m;
        cin >> l >> r >> m;
        bool found = false;
        for (ll a = l; a <= r; ++a) {
            ll rm = m % a;
            if (rm == 0) {
                cout << a << ' ' << a << ' ' << a << '\n';
                found = true;
                break;
            }
            ll comp = a - rm;
            if (r - comp >= l) {
                cout << a << ' ' << r - comp << ' ' << r << '\n';
                found = true;
                break;
            } 
            if (l + rm <= r) {
                cout << a << ' ' << l + rm << ' ' << l << '\n';
                found = true;
                break;
            }
        }
        assert(found);
    }
    return 0;
}
