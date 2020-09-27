#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] {
    return ios::sync_with_stdio(false), cin.tie(nullptr);
}();

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, t;
        cin >> n >> t;
        vector<ll> a(n);
        for (auto &i : a) cin >> i;
        map<ll, vector<ll>> pos;
        for (int i = 0; i < n; ++i) {
            pos[a[i]].emplace_back(i);
        }
        vector<int> w, r;
        vector<bool> mark(n, false);
        auto Add = [&](int i) {
            while (!pos[t - a[i]].empty() && mark[pos[t - a[i]].back()]) {
                pos[t - a[i]].pop_back();
            }
            if (!pos[t - a[i]].empty()) {
                if (a[i] > t - a[i]) {
                    w.emplace_back(i);
                    r.emplace_back(pos[t - a[i]].back());
                } else {
                    r.emplace_back(i);
                    w.emplace_back(pos[t - a[i]].back());
                }
                mark[pos[t - a[i]].back()] = true;
                pos[t - a[i]].pop_back();
            } else {
                if (a[i] > t - a[i]) w.emplace_back(i);
                else r.emplace_back(i);
                
            }
        };
        for (int i = 0; i < n; ++i) {
            if (mark[i]) continue;
            mark[i] = true;
            Add(i);
        }
        vector<int> ans(n);
        assert(int(size(w)) + int(size(r)) == n);
        for (auto &i : w) ans[i] = 1;
        for (auto &i : r) ans[i] = 0;
        for (auto &i : ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
