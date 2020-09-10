#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif
#define all(v) (v).begin(), (v).end()
using ll = long long;
}
using namespace Util;

int constexpr N = (int) 2.1e5;

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> b(n);
    for (auto &i : b) cin >> i;
    sort(all(a), greater<int>());
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](auto &lhs, auto &rhs) {
        return b[lhs] < b[rhs];
    });
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[idx[i]] = a[i];
    }
    for (auto &i : ans) cout << i << ' ';
    return 0;
}
