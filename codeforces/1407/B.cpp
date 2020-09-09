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


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &i : a) cin >> i;

        vector<ll> b(n);
        set<ll> mark;
        ll pregcd = 0;
        for (int i = 0; i < n; ++i) {
            ll mxi = -1, mxgcd = INT_MIN;
            for (int j = 0; j < n; ++j) {
                if (mark.count(j)) continue;
                if (__gcd(pregcd, a[j]) >= mxgcd) {
                    mxi = j;
                    mxgcd = __gcd(pregcd, a[j]);
                }
            }
            b[i] = a[mxi];
            pregcd = mxgcd;
            mark.emplace(mxi);
        }

        for (auto &i : b) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
