#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] {
    return ios::sync_with_stdio(false), cin.tie(nullptr);
}();

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool has_even = false, has_odd = false;
    for (auto &i : a) {
        cin >> i;
        has_odd |= i & 1;
        has_even |= !(i & 1);
    }
    if (has_odd && has_even) {
        sort(begin(a), end(a));
        for (auto &i : a) cout << i << ' ';
    } else {
        for (auto &i : a) cout << i << ' ';
    }
    return 0;
}
