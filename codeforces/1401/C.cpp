#include <bits/stdc++.h>
using namespace std;
const int _R = [] { ios::sync_with_stdio(false), cin.tie(nullptr); return 1; }();
#ifdef LOCAL
#define dbg(a) cerr << "\"" << #a << "\"=" << a << '\n'
#else
#define dbg(a) 0
#endif

constexpr int N = int(1e5) + 10;

int a[N], b[N];

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        memcpy(b, a, n * sizeof(int));
        int mn = *min_element(a, a + n);
        sort(b, b + n);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                if (b[i] % mn != 0) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
