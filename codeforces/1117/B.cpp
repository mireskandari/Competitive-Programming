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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    sort(all(a));
    ll last = a.back(), llast = *next(a.rbegin());
    cout << (m / (k + 1)) * (k * last + llast) + (m % (k + 1)) * last;
    return 0;
}
