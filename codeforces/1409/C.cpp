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
    int tc; cin >> tc;
    while (tc--) {
        long n, x, y; cin >> n >> x >> y;
        deque<long> best{LLONG_MAX};
        for (int diff = 1; diff <= (y - x); ++diff) {
            deque<long> a{y};
            long prv = y - diff;
            while ((int) a.size() < n) {
                if (prv <= 0) break;
                a.emplace_front(prv);
                prv = prv - diff;
            }
            while ((int) a.size() < n) {
                a.emplace_back(a.back() + diff);
            }
            assert((int) a.size() == n);
            if (find(all(a), x) != a.end() && a.back() < best.back()) {
                swap(a, best);
            }
        }
        for (auto &i : best) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
