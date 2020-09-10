#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif
#define all(v) (v).begin(), (v).end()
using ll = long long;
}
using namespace Util;

void no() {
    cout << -1;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> g(n);
    vector<ll> deg(n);
    for (int i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        g[--v].emplace(--u);
        g[u].emplace(v);
        deg[v]++;
        deg[u]++;
    }
    set<ll> f{0};
    for (int i = 1; i < n; ++i) {
        if (!g[0].count(i)) {
            f.emplace(i);
        }
    }
    ll second_v = 0;
    while (second_v < n && f.count(second_v)) {
        ++second_v;
    }
    if (second_v == n) no();
    set<ll> s{second_v};
    for (int i = 0; i < n; ++i) {
        if (i != second_v && !g[second_v].count(i)) {
            s.emplace(i);
        }
    }
    ll third_v = 0;
    while (third_v < n && (f.count(third_v) || s.count(third_v))) {
        ++third_v;
    }
    if (third_v == n) no();
    set<ll> t{third_v};
    for (int i = 0; i < n; ++i) {
        if (i != third_v && !g[third_v].count(i)) {
            t.emplace(i);
        }
    }
    // fjkcehfkddbjkgbjkdfhvngfdcjkcghjhsd
    for (int i = 0; i < n; ++i) {
        int cnt = f.count(i) + s.count(i) + t.count(i);
        if (cnt != 1) no();
    }
    ll sz1 = (ll) f.size(), sz2 = (ll) s.size(), sz3 = (ll) t.size();
    if (m != sz1 * sz2 + sz1 * sz3 + sz2 * sz3) no();
    auto check = [&](set<ll> &st) {
        for (auto &v : st) {
            if (deg[v] != n - (ll) st.size()) no();
            for (auto &u : g[v]) {
                if (st.count(u)) no();
            }
        }
    };
    check(f);
    check(s);
    check(t);
    for (int i = 0; i < n; ++i) {
        if (f.count(i)) {
            cout << 1;
        }
        if (s.count(i)) {
            cout << 2;
        }
        if (t.count(i)) {
            cout << 3;
        }
        cout << ' ';
    }
    return 0;
}
