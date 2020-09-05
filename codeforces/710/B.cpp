#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a) 0
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
}
using namespace Util;


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    vector<long> a(n); for (auto &i : a) cin >> i;
    auto Solve = [&](long p) {
        long res = 0;
        for (int i = 0; i < n; ++i) {
            res += abs(a[i] - p);
        }
        return res;
    };
    long R = 1e9 + 10, L = -1e9 - 10;
    while (R - L > 2) {
        long mid1 = L + (R - L) / 3;
        long mid2 = R - (R - L) / 3;
        if (Solve(mid1) > Solve(mid2)) {
            L = mid1;
        } else {
            R = mid2;
        }
        dbg(L); dbg(R);
    }
    long idx = L;
    for (int i = L + 1; i <= R; ++i) {
        if (Solve(idx) > Solve(i)) {
            idx = i;
        }
    }
    cout << idx;
    return 0;
}
