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
    string s; cin >> s;
    int aa = s[0] - 'a' + 1, b = s[1] - '0', cnt = 0;
    dbg(aa); dbg(b);
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i == 0 && j == 0) continue;
            if (aa + i <= 8 && b + j <= 8 && aa + i >= 1 && b + j >= 1) {
                ++cnt;
            }
        }
    }
    cout << cnt;
    return 0;
}
