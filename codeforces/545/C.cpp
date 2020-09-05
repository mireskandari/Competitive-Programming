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
    vector<array<int, 2>> a(n); for (auto &i : a) cin >> i[0] >> i[1];
    if (n == 1) {
        cout << 1;
        exit(0);
    }
    bool prv_left = true;
    int cnt = 2;
    auto Dist = [&](int i, int j) {
        return a[j][0] - a[i][0] - 1;
    };
    for (int i = 1; i < n - 1; ++i) {
        if (prv_left) {
            if (Dist(i - 1, i) >= a[i][1]) {
                ++cnt;
            } else if (Dist(i, i + 1) < a[i][1]) {
                // we're good
            } else {
                ++cnt;
                prv_left = false;
            }
        } else {
            if (Dist(i - 1, i) - a[i - 1][1] >= a[i][1]) {
                ++cnt;
                prv_left = true;
            } else if (Dist(i, i + 1) < a[i][1]) {
                prv_left = true;
            } else {
                ++cnt;
            }
        }
        dbg(i); dbg(cnt);
    }
    cout << cnt;
    return 0;
}
