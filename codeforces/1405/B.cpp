#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
}
using namespace Util;


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<long> a(n);
        for (auto &i : a) cin >> i;
        long pos_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                pos_sum = max<long>(0, pos_sum + a[i]);
            } else {
                pos_sum += a[i];
            }
        }
        cout << pos_sum << '\n';
    }
    return 0;
}