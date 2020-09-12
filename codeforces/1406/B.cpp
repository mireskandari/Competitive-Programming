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

#define int ll
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> neg, pos;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
            if (i < 0) neg.emplace_back(-i);
            else pos.emplace_back(i);
        }
        sort(neg.rbegin(), neg.rend());
        sort(pos.rbegin(), pos.rend());
        if (pos.empty()) {
            reverse(all(neg));
            cout << -(neg[0] * neg[1] * neg[2] * neg[3] * neg[4]) << '\n';
            continue;
        }
        sort(a.rbegin(), a.rend());
        ll mx = a[0] * a[1] * a[2] * a[3] * a[4];
        for (int i = 0; i < 5; i += 2) {
            if (i > (int) neg.size() || 5 - i > (int) pos.size()) continue;
            ll now = 1;
            for (int j = 0; j < i; ++j) now *= neg[j];
            for (int j = 0; j < 5 - i; ++j) now *= pos[j];
            mx = max(mx, now);
        }
        assert(mx != LLONG_MIN);
        cout << mx << '\n';
    }
    return 0;
}
