#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();

ll nc2(int n) {
    if (n < 2) return 0;
    return (1ll * n * (n - 1)) >> 1;
}

signed main() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
    map<array<ll, 2>, int> cnt;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i][0] - a[j][0] == 0 || a[i][1] - a[j][1] == 0)
                ++cnt[{abs(a[i][0] - a[j][0]), abs(a[i][1] - a[j][1])}];
            else if (a[i][0] - a[j][0] > 0)
                ++cnt[{a[i][0] - a[j][0], a[i][1] - a[j][1]}];
            else
                ++cnt[{-a[i][0] + a[j][0], -a[i][1] + a[j][1]}];
        }
    }
    ll ans = 0;
    for (auto &i : cnt) { 
        ans += nc2(i.second);
    }
    cout << ans / 2;
    return 0;
}
