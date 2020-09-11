// caution: fucking implementation
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

int8_t constexpr AND = 0, OR = 1, XOR = 2, NOT = 3, IN = 4;
int constexpr N = (int) 1.1e6;

vector<int> g[N];
int8_t type[N];
bool a[N], dp[N];

bool dfs_val(int v) {
    switch (type[v]) {
        case IN: break;
        case AND: (a[v] = dfs_val(g[v][0]) & dfs_val(g[v][1])); break;          
        case OR: (a[v] = dfs_val(g[v][0]) | dfs_val(g[v][1])); break;
        case XOR: (a[v] = dfs_val(g[v][0]) ^ dfs_val(g[v][1])); break;
        case NOT: (a[v] = !dfs_val(g[v][0])); break;
    }
    return a[v];
}

void dfs_dp(int v, int p) {
    if (v == 0) {
        dp[v] = true;
    } else {
        auto check = [&](auto f) {
            if (type[p] == NOT) return true;
            int sibling = g[p][0] + g[p][1] - v;
            return f(a[v], a[sibling]) != f(!a[v], a[sibling]);
        };
        switch (type[p]) {
            case AND: dp[v] = dp[p] && check([](bool a, bool b) { return a & b; }); break;
            case OR: dp[v] = dp[p] && check([](bool a, bool b) { return a | b; }); break;
            case XOR: dp[v] = dp[p] && check([](bool a, bool b) { return a ^ b; }); break;
            case NOT: dp[v] = dp[p] && check([](bool a, bool b) { return 1; }); break;
        }
    }
    for (auto &u : g[v]) {
        dfs_dp(u, v);
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        if (t == "IN") type[i] = IN;
        if (t == "NOT") type[i] = NOT;
        if (t == "AND") type[i] = AND;
        if (t == "OR") type[i] = OR;
        if (t == "XOR") type[i] = XOR;

        if (t == "IN") {
            int v;
            cin >> v;
            a[i] = v;
        } else {
            vector<int> adj;
            if (t == "NOT") {
                int v;
                cin >> v;
                adj.emplace_back(v);
            } else {
                int v, u;
                cin >> v >> u;
                adj.emplace_back(v);
                adj.emplace_back(u);
            }
            for (auto u : adj) {
                g[i].emplace_back(--u);
            }
        }
    }
    dfs_val(0);
    dfs_dp(0, -1);
    for (int i = 0; i < n; ++i) {
        if (type[i] == IN) {
            cout << (dp[i] ? !a[0] : a[0]);
        }
    }
    return 0;
}
