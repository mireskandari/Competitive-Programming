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

long int_sum(long a) {
    long res = 0;
    while (a) {
        res += a % 10;
        a /= 10;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        long n, s; cin >> n >> s;
        long nn = n, pw10 = 1;
        for (int i = 0; int_sum(n) > s; ++i, pw10 *= 10) {
            n += pw10 * (10 - (n / pw10) % 10);
        }
        cout << n - nn << '\n';
    }
    return 0;
}
