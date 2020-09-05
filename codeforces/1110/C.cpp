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
    map<int, int> ans;
    ans[2] = 3;
    ans[3] = 1;
    ans[7] = 1;
    ans[15] = 5;
    ans[31] = 1;
    ans[63] = 21;
    ans[127] = 1;
    ans[255] = 85;
    ans[511] = 73;
    ans[1023] = 341;
    ans[2047] = 89;
    ans[4095] = 1365;
    ans[8191] = 1;
    ans[16383] = 5461;
    ans[32767] = 4681;
    ans[65535] = 21845;
    ans[131071] = 1;
    ans[262143] = 87381;
    ans[524287] = 1;
    ans[1048575] = 349525;
    ans[2097151] = 299593;
    ans[4194303] = 1398101;
    ans[8388607] = 178481;
    ans[16777215] = 5592405;
    ans[33554431] = 1082401;
    int tc; cin >> tc;
    while (tc--) {
        int x; cin >> x;
        if (ans.find(x) == ans.end()) {
            ans[x] = (1 << ((int) ceil(log2(x)))) - 1;
        }
        cout << ans[x] << '\n';
    }
    return 0;
}
