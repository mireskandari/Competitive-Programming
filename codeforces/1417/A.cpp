#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] {
    return ios::sync_with_stdio(false), cin.tie(nullptr);
}();

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        sort(begin(a), end(a));
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (k > a[i]) cnt += (k - a[i]) / a[0];
        }
        cout << cnt << '\n';
    }
    return 0;
}