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

// nice a :|
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &i : a) cin >> i;
        vector<ll> pos0, pos1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) pos0.emplace_back(i);
            else pos1.emplace_back(i);
        }
        if (pos0.size() < pos1.size()) {
            swap(pos0, pos1);
            if ((int) pos0.size() & 1) {
                pos0.pop_back();
            }
        }
        cout << pos0.size() << '\n';
        for (auto &i : pos0) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
