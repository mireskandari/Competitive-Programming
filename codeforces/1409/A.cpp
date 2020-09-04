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
        long a, b; cin >> a >> b;
        long diff = abs(a - b);
        cout << diff / 10 + (diff % 10 > 0) << '\n';
    }
    return 0;
}
