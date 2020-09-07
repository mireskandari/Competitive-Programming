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

inline void chmin(ll &a, ll b) {
    a = a > b ? b : a;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    
    vector<ll> a(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }

    vector<array<ll, 2>> seg(m);
    for (int i = 0; i < m; ++i) {
        int f, s;
        cin >> f >> s;
        --f; --s;
        seg[i] = {min(pos[f], pos[s]), max(pos[f], pos[s])};
    }
    
    sort(all(seg));

    vector<ll> next_r(n, INT_MAX);
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) next_r[i] = next_r[i + 1];
        
        while (!seg.empty() && seg.back()[0] == i) {
            chmin(next_r[i], seg.back()[1]);
            seg.pop_back();
        }
    }

    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (next_r[i] == INT_MAX) {
            cnt += n - i;
        } else {
            cnt += next_r[i] - i;
        }
    }
    
    cout << cnt;
    return 0;
}
