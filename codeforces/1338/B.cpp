#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
void err() { cerr << '\n'; }
template <class T, class ...A>
void err(T a, A ...b) {
    cerr << " " << a; err(b...);
}
#define dbg(a...) cerr << __LINE__ << " [" << #a << "]:", err(a)
#else
#define dbg(a...) 0
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t


long n, m;
vector<vector<long>> g;
vector<long> depth;
vector<bool> leaf, mark, has_leaf;

void Reset() {
    g.assign(n, vector<long>());
    depth.resize(n);
    leaf.resize(n, false);
    has_leaf.assign(n, false);
    mark.assign(n, false);
}

void Dfs(long v) {
    mark[v] = true;
    for (auto &u : g[v]) {
        if (!mark[u]) {
            depth[u] = depth[v] + 1;
            if (leaf[u]) has_leaf[v] = true;
            Dfs(u);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    m = n - 1;
    Reset();
    long st = 0;
    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }

    for (int i = 0; i < n; ++i) {
        leaf[i] = (int) g[i].size() <= 1;
        if (!leaf[i]) st = i;
    }

    depth[st] = 0;
    Dfs(st);

    vector<long> parity(2);
    for (int i = 0; i < n; ++i) {
        if (leaf[i]) {
            ++parity[depth[i] % 2];
        }
    }
    
    cout << (parity[0] && parity[1] ? 3 : 1) << ' ';
    cout << m - count(all(leaf), true) + count(all(has_leaf), true);

    return 0;
}
