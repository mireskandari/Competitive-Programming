#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(a) cerr << "\"" << #a << "\"=" << a << '\n'
#else
#define dbg(a) 0
#endif

int64_t constexpr INF = int64_t(1e14);

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int64_t> s(n), c(n);
    for (auto &i : s) cin >> i;
    for (auto &i : c) cin >> i;
    int64_t best = INF;
    for (int i = 0; i < n; ++i) {
        int64_t cost = c[i];
        int64_t mn = INF;
        for (int j = 0; j < i; ++j) {
            if (s[j] < s[i]) {
                mn = min(mn, c[j]);
            }
        }
        cost += mn;
        mn = INF;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] > s[i]) {
                mn = min(mn, c[j]);
            }
        }
        cost += mn;
        best = min(best, cost);
    }
    cout << (best >= INF ? -1 : best);
    return 0;
}
