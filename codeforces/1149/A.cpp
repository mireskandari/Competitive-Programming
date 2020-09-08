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

bool is_prime(ll a) {
    for (ll i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    
    ll cnt1 = count(all(a), 1), cnt2 = count(all(a), 2);
    ll sum = 0;
    if (!cnt2 || !cnt1) {
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            cout << a[i] << ' ';
        }
    } else {
        cout << 2 << ' ' << 1 << ' ';
        sum = 3;
        --cnt2; 
        --cnt1;

        for (int i = 2; i < n; ++i) {
            if (cnt2) {
                cout << 2 << ' ';
                --cnt2;
            } else {
                cout << 1 << ' ';
            }
        }
    }
    return 0;
}
