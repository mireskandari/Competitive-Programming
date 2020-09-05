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
    int b, k; cin >> b >> k;
    vector<int> a(k); for (auto &i : a) cin >> i;
    int x = 0;
    for (int i = 0; i < k - 1; ++i) {
        if (b & 1) {
            if (a[i] & 1) x ^= 1;
        }
    }
    x ^= (a.back() & 1);
    cout << (x ? "odd" : "even");
    return 0;
}
