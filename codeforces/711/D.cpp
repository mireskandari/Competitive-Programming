#include <stdio.h>
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

int constexpr P = 1000000007;

ll norm(ll a) {
    if (a >= P) a -= P;
    if (a < 0) a += P;
    return a;
}

ll binpow(ll a, ll x) {
    dbg(a); dbg(x);
    ll res = 1;
    while (x) {
        if (x & 1) (res *= a) %= P;
        (a *= a) %= P;
        x >>= 1;
    }
    return res;
}

int constexpr N = (int) 2.1e5;

int depth[N], cycle_sz[N], sz[N];
int8_t mark[N];
vector<int> g[N];

void dfs(int v, int idx) {
    mark[v] = 1;
    sz[idx]++;
    for (auto &u : g[v]) {
        if (mark[u] == 0) {
            depth[u] = depth[v] + 1;
            dfs(u, idx);
        } else if (mark[u] == 1) {
            cycle_sz[idx] = depth[v] - depth[u] + 1;
        }
        if (cycle_sz[idx] > 0) {
            mark[v] = 2;
            return;
        }
    }
    mark[v] = 2;
}

signed main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int v;
        scanf("%d", &v);
        g[i].emplace_back(--v);
    }
    ll ans = 1;
    for (int i = 0, component = 0; i < n; ++i) {
        if (mark[i] == 0) {
            component++;
            dfs(i, component);
            if (cycle_sz[component] > 0) {
                (ans *= norm(binpow(2, cycle_sz[component]) - 2)) %= P;
            }
            (ans *= binpow(2, sz[component] - cycle_sz[component])) %= P;
        }
    }
    printf("%lld", ans);
    return 0;
}
