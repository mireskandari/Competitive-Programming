#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif

#define all(v) (v).begin(), (v).end()
using ll = int64_t;
}
using namespace Util;

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return abs(y2 - y1) + abs(x2 - x1);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll f, s, x, y, n;
    cin >> f >> s >> x >> y >> n;
    string t;
    cin >> t;

    vector<array<ll, 2>> pref(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = (i != 0 ? pref[i - 1] : array<ll, 2>{0, 0});
        switch (t[i]) {
            case 'U': pref[i][1]++; break;
            case 'D': pref[i][1]--; break;
            case 'R': pref[i][0]++; break;
            case 'L': pref[i][0]--; break;
        }
    }

    auto solve = [&](ll day) {
        ll dv = day / n;
        ll rm = day % n;
        if (rm == 0) {
            return dist(f + dv * pref.back()[0], s + dv * pref.back()[1], x, y);
        }
        return dist(f + dv * pref.back()[0] + pref[rm - 1][0], s + dv * pref.back()[1] + pref[rm - 1][1], x, y);
    };

    ll R = 5e17, L = 0;
    while (R - L > 1) {
        ll M = (R + L) >> 1;
        if (solve(M) <= M) {
            R = M;
        } else {
            L = M;
        }
        dbg(L); dbg(R);
    }
    
    if (solve(L) > L && solve(R) > R) {
        cout << -1;
        exit(0);
    }

    cout << (solve(L) <= L ? L : R);
    return 0;
}
