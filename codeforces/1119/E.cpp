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


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    ll carry = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        ll now = a[i] / 2;
        if (now <= carry) {
            carry -= now;
            carry += a[i] - 2 * now;
            cnt += now;
        } else {
            cnt += carry;
            a[i] -= 2 * carry;
            carry = a[i] % 3;
            cnt += a[i] / 3;
        }
        dbg(cnt); dbg(i); dbg(carry);
    }
    cout << cnt;
    return 0;
}
