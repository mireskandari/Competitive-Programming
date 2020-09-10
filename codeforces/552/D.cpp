#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif
#define all(v) (v).begin(), (v).end()
using ll = long long;
}
using namespace Util;

ll nc3(ll n) {
    if (n < 3) return 0;
    return (n * (n - 1) * (n - 2)) / 6;
}

ll nc2(ll n) {
    if (n < 2) return 0;
    return (n * (n - 1)) / 2;
}

array<ll, 2> get_slope(array<ll, 2> f, array<ll, 2> s) {
    ll n = (s[1] - f[1]), d = (s[0] - f[0]);
    if (n == 0 && d == 0) return array<ll, 2>{0, 0};
    ll g = __gcd(n, d);
    n /= g;
    d /= g;
    return array<ll, 2>{n, d};
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    ll ans = nc3(n);
    vector<array<ll, 2>> a(n);
    for (auto &i : a) cin >> i[0] >> i[1];
    vector<bool> mark(n);
    for (int i = 0; i < n; ++i) {
        dbg(i);
        map<array<ll, 2>, ll> cnt;
        for (int j = 0; j < n; ++j) {
            if (j == i || mark[j]) continue;
            cnt[get_slope(a[i], a[j])]++;
        }
        for (auto &p : cnt) {
            dbg(p.first[0]); dbg(p.first[1]); dbg(p.second);
            ans -= nc2(p.second);
        }
        mark[i] = true;
    }
    cout << ans;
    return 0;
}
