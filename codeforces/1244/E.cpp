#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
#define show(a) #a << ' ' << a << ' '
#define int ll

signed main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<ll> pref(n + 1);
    partial_sum(a.begin(), a.end(), pref.begin());
    
    auto sum = [&](int l, int r) { // inclusive
        return pref[r] - pref[l - 1];
    };
    
    ll best = LLONG_MAX;
    auto check_max = [&](int i) {
         ll init_cost = sum(i, n) - (n - i + 1) * a[i]; 
        auto check = [&](ll x) {
            int idx = lower_bound(a.begin() + 1, a.end(), x) - a.begin();
            ll sec_cost = (idx - 1) * x - sum(1, idx - 1);
            return sec_cost + init_cost <= k;
        };
        ll low = 0, high = a[i];
        while (high - low > 1) {
            ll mid = low + (high - low) / 2;
            if (check(mid)) low = mid;
            else high = mid;
        }
        if (check(high)) low = high;
        if (!check(low)) return;
        best = min(best, a[i] - low);
    };

    auto check_min = [&](int i) {
        ll init_cost = (i - 1) * a[i] - sum(1, i - 1);
        auto check = [&](ll x) {
            int idx = upper_bound(a.begin() + 1, a.end(), x) - a.begin();
            ll sec_cost = idx == n + 1 ? 0 : sum(idx, n) - (n - idx + 1) * x;
            return sec_cost + init_cost <= k;
        };
        ll low = a[i], high = 1e9 + 10;
        while (high - low > 1) {
            ll mid = low + (high - low) / 2;
            if (check(mid)) high = mid;
            else low = mid;
        }
        if (!check(low)) low = high;
        if (!check(low)) return;
        best = min(best, low - a[i]);
    };

    for (int i = 1; i <= n; ++i) {
        check_max(i);
        check_min(i);
    }
    
    cout << best;
    return 0;
}
