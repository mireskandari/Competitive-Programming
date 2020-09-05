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
    vector<int> c(n); for (auto &i : c) cin >> i;
    vector<int> t(n); for (auto &i : t) cin >> i;
    vector<int> dc(n - 1);
    for (int i = 1; i < n; ++i) {
        dc[i - 1] = c[i] - c[i - 1];
    }
    vector<int> dt(n - 1);
    for (int i = 1; i < n; ++i) {
        dt[i - 1] = t[i] - t[i - 1];
    }
    cout << (c[0] == t[0] && multiset<int>(all(dc)) == multiset<int>(all(dt)) ? "Yes" : "No");
    return 0;
}
