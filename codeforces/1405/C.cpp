#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
}
using namespace Util;


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        bool ok = true;
        for (int i = k; i < n; ++i) {
            if (s[i] != '?') {
                if (s[i % k] == '?') s[i % k] = s[i];
                else if (s[i % k] != s[i]) ok = false;
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        int fre = 0, sum = 0;
        for (int i = 0; i < k; ++i) {
            if (s[i] != '?') sum += (s[i] == '1' ? 1 : -1);
            else ++fre;
        }

        cout << (abs(sum) <= fre ? "YES\n" : "NO\n");
    }
    return 0;
}
