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


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;

    vector<ll> dp(n);
    vector<ll> mx_dp((size_t) 1e5 + 10);

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        
        vector<ll> pf;
        for (ll j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                pf.emplace_back(j); 
                while (a[i] % j == 0) a[i] /= j;
            }
        }
        if (a[i] > 1) pf.emplace_back(a[i]);
        
        for (auto &j : pf) {
            dp[i] = max(dp[i], mx_dp[j] + 1);
        }
        for (auto &j : pf) {
            mx_dp[j] = max(mx_dp[j], dp[i]);
        }
    }

    cout << *max_element(all(dp));
    return 0;
}
