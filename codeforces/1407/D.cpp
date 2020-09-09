#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif

#define all(v) (v).begin(), (v).end()
using ll = int64_t;
}
using namespace Util;

ll constexpr INF = (ll) 1e18;

void chmin(ll &a, ll b) {
    a = a > b ? b : a;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    
    vector<ll> dp(n, INF);
    stack<ll> st1, st2;
    for (int i = 0; i < n; ++i) {
        dp[i] = i != 0 ? dp[i - 1] + 1 : 0;
   
        // higher
        while (!st1.empty() && a[st1.top()] > a[i]) {
            chmin(dp[i], dp[st1.top()] + 1);
            st1.pop();
        }
        if (!st1.empty()) {
            chmin(dp[i], dp[st1.top()] + 1);
            if (a[st1.top()] == a[i]) st1.pop(); // retarded :|
        }
        st1.emplace(i);
        
        // lower
        while (!st2.empty() && a[st2.top()] < a[i]) {
            chmin(dp[i], dp[st2.top()] + 1);
            st2.pop();
        }
        if (!st2.empty()) {
            chmin(dp[i], dp[st2.top()] + 1);
            if (a[st2.top()] == a[i]) st2.pop();
        }
        st2.emplace(i);
    }

    cout << dp.back();
    return 0;
}
