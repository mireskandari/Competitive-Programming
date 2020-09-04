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
    int tc; cin >> tc;
    while (tc--) {
        long a, b, x, y; cin >> a >> b >> x >> y;
        long n; cin >> n;
        long a1 = max(a - n, x); long b1 = max(y, b - (n - a + a1));
        long b2 = max(b - n, y); long a2 = max(x, a - (n - b + b2));
        cout << min(a1 * b1, b2 * a2) << '\n';
    }
    return 0;
}
