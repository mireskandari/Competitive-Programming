#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();

#include <bits/extc++.h>
using namespace __gnu_pbds;
using pbds = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

struct fenw {
    vector<ll> a;
    fenw(int n_) : a(n_ + 1) {}
    void update(int idx, ll x) {
        for (++idx; idx < int(a.size()); idx += idx & -idx) a[idx] += x;
    }
    ll query(int idx) {
        ll res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) res += a[idx];
        return res;
    }
};

signed main() {
    int n; 
    cin >> n;
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; ++i) cin >> s[i];
    fenw f(n + 1);
    for (int i = 1; i <= n; ++i) f.update(i, i);
    pbds st;
    for (int i = 1; i <= n; ++i) st.insert(i);
    vector<int> a(n + 1);
    for (int i = n; i > 0; --i) {
        auto solve = [&](ll x) {
            return f.query(*st.find_by_order(x) - 1) < s[i];
        };
        int L = 0, R = int(st.size());
        while (R - L > 1) {
            int M = (R + L) >> 1;
            if (solve(M)) {
                L = M + 1;
            } else {
                R = M;
            }
        }
        if (solve(L)) L = R;
        int val = *st.find_by_order(L);
        a[i] = val;
        st.erase(val);
        f.update(val, -val);
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}
