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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        vector<int> cnt(1000);
        for (auto &i : a) cnt[i]++;
        int aa = 0;
        for (int i = 0; i < 1000; ++i) {
            if (cnt[i] == 0) {
                break;
            }
            cnt[i]--;
            aa++;
        }
        int bb = 0;
        for (int i = 0; i < 1000; ++i) {
            if (cnt[i] == 0) {
                break;
            }
            bb++;
        }
        cout << aa + bb << '\n';
    }
    return 0;
}
