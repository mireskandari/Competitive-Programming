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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n); for (auto &i : a) cin >> i;
    vector<int> diff; diff.reserve(n);
    for (int i = 1; i < n; ++i) {
        diff.emplace_back(a[i] - a[i - 1]);
    }
    sort(all(diff));
    if (k >= n) {
        cout << n;
        exit(0);
    }
    long sum = 0;
    for (int i = 0; n > k; ++i, --n) {
        sum += diff[i];
    }
    cout << sum + n;
    return 0;
}
