#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a) 0
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
}
using namespace Util;


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    long n, p, k; cin >> n >> p >> k;
    vector<long> a(n); for (auto &i : a) cin >> i;
    
    long cnt_all = 0;
    vector<long> b(n);
    map<long, long> cnt;
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
        for (int _ = 0; _ < 3; ++_) {
            (b[i] *= a[i]) %= p;
        }
        b[i] -= k * a[i]; b[i] %= p;
        b[i] += p; b[i] %= p;
        cnt_all += cnt[b[i]];
        cnt[b[i]]++;
    }
    
    cout << cnt_all;
    return 0;
}
