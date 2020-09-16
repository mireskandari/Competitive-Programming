#include <bits/stdc++.h>
#define dbg(a) 0
// #define dbg(a) cerr << "\"" << #a << "\":" << a << '\n'
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (auto &i : a) cin >> i;
        ll mx = *max_element(a.begin(), a.end());
        if (find(a.begin(), a.end(), x) != a.end()) {
            cout << 1 << '\n';
            continue;
        }
        if (mx > x) {
            cout << 2 << '\n';
            continue;
        }
        cout << (x + mx - 1) / mx << '\n';
    }
    return 0;
}
