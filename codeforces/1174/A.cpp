#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] {
    return ios::sync_with_stdio(false), cin.tie(nullptr);
}();

signed main() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto &i : a) cin >> i;
    sort(begin(a), end(a));
    if (accumulate(begin(a), begin(a) + n, 0ll) == accumulate(begin(a) + n, end(a), 0ll)) {
        cout << -1;
    } else {
        for (auto &i : a) cout << i << ' ';
    }
    return 0;
}
