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

long constexpr P = 1e9 + 9, B = 31;

long Pow(long a, long x) {
    long res = 1;
    while (x) {
        if (x & 1) (res *= a) %= P;
        (a = a * a) %= P;
        x >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // yay hashing
    vector<long> pw((size_t) 4e5), invpw((size_t) 4e5);
    pw[0] = 1;
    for (int i = 1; i < (int) pw.size(); ++i) {
        pw[i] = pw[i - 1] * B; pw[i] %= P;
    }
    invpw.back() = Pow(pw.back(), P - 2);
    for (int i = (int) invpw.size() - 1; i >= 1; --i) {
        invpw[i - 1] = invpw[i] * B; invpw[i - 1] %= P;
    }

    vector<long> cnt((size_t) 4e5);
    set<long> av;
    
    long tc; cin >> tc;
    while (tc--) {
        int command; cin >> command;
        string s; cin >> s;
        int n = (int) s.size();
        vector<long> hsh(n + 1);
        hsh[0] = 0;
        for (int i = 1; i <= n; ++i) {
            long tmp = pw[i - 1] * (s[i - 1] - 'a' + 1);
            tmp %= P;
            hsh[i] = hsh[i - 1] + tmp;
            if (hsh[i] >= P) hsh[i] -= P;
        }
        if (command == 1) {
            cnt[n]++;
            av.emplace(hsh[n]);
        } else if (command == 2) {
            cnt[n]--;
            av.erase(hsh[n]);
        } else {
            long ans = 0;
            for (int len = 1; len <= n; ++len) {
                if (!cnt[len]) continue;
                for (int i = 1; i + len - 1 <= n; ++i) {
                    long hsh2 = hsh[i + len - 1] - hsh[i - 1];
                    hsh2 %= P;
                    if (hsh2 < 0) hsh2 += P;
                    (hsh2 *= invpw[i - 1]) %= P;
                    if (av.count(hsh2)) ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
