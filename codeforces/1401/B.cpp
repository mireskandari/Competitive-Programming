#include <bits/stdc++.h>
using namespace std;
const int _R = [] { ios::sync_with_stdio(false), cin.tie(nullptr); return 1; }();
#ifdef LOCAL
#define dbg(a) cerr << "\"" << #a << "\"=" << a << '\n'
#else
#define dbg(a) 0
#endif

signed main() {
    using ll = int64_t;
    ll tc;
    cin >> tc;
    while (tc--) {
        ll a[3], b[3];
        cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
        ll x = min(a[1], b[0]); 
        a[1] -= x; 
        b[0] -= x;
        x = min(b[2], a[0]); 
        a[0] -= x; 
        b[2] -= x;
        cout << min(a[2], b[1]) * 2 - min(b[2], a[1]) * 2 << '\n';
    }
    return 0;
}

