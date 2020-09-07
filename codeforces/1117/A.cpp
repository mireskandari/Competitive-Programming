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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    int mx = *max_element(all(a));
    int best = 0, now = a[0] == mx;
    for (int i = 1; i < n; ++i) {
        if (a[i] == mx) {
            ++now;
        } else {
            best = max(now, best);
            now = 0;
        }
    }
    best = max(now, best);
    cout << best;
    return 0;
}
