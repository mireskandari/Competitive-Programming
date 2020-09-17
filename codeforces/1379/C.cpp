#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
#define dbg(a) 0
// #define dbg(a) cerr << __LINE__ << " \"" << #a << "\":" << a << '\n'

#define int ll

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> m >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        if (m == 1) {
            cout << *max_element(a.begin(), a.end()) << '\n';
            continue;
        }
        {
            vector<ll> idx(n);
            iota(idx.begin(), idx.end(), 0);
            sort(idx.begin(), idx.end(), [&](const auto &lhs, const auto &rhs) {
                return a[lhs] < a[rhs];
            });
            vector<ll> temp(n);
            for (int i = 0; i < n; ++i) {
                temp[i] = b[idx[i]];
            }
            swap(temp, b);
        }
        sort(a.begin(), a.end());
        vector<ll> suff(n);
        partial_sum(a.rbegin(), a.rend(), suff.rbegin());
        ll mx = 0;
        if (m < n) mx = max(mx, suff[n - m]);
        suff.emplace_back(0);
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
            ll cnt = n - j + 1;
            if (a[i] >= b[i]) --cnt;
            if (cnt > m) continue;
            ll sum = (cnt == n - j + 1 ? a[i] + suff[j] : suff[j]) + (m - cnt) * b[i];
            mx = max(mx, sum);
            dbg(i); dbg(sum);
        }
        cout << mx << '\n';
    }
    return 0;
}
