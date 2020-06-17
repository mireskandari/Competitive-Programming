#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p, d, w;
    cin >> n >> p >> w >> d;
    if (p % __gcd(d, w)) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i <= max(w, d); i++) {
        int res1 = p - i * w;
        int res2 = p - i * d;
        if (res1 % d == 0) if (res1 / d + i <= n) {
            if (res1 / d >= 0) return cout << i << ' ' << res1 / d << ' ' << n - i - res1 / d, 0;
        }
        if (res2 % w == 0) if (res2 / w + i <= n) {
            if (res2 / w >= 0) return cout << res2 / w << ' ' << i << ' ' << n - i - res2 / w, 0;
        }
    }
    cout << -1;
    return 0;
}