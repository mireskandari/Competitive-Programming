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


long n;
vector<vector<long>> g;
vector<long> depth;
vector<bool> mark, has_leaf, leaf;

void Reset() {
    g.assign(n, vector<long>());
    depth.resize(n);
    mark.assign(n, false);
    leaf.assign(n, false);
    has_leaf.assign(n, false);
}

void Dfs(long v) {
    mark[v] = true;
    for (auto &u : g[v]) {
        if (!mark[u]) {
            depth[u] = depth[v] + 1;
            Dfs(u);
        }
    }
}

bool CheckMin() {
    for (int i = 0; i < n; ++i) {
        if ((int) g[i].size() <= 1) {
            leaf[i] = true;
            has_leaf[g[i][0]] = true;
        }
    }

    vector<long> parity(2);
    for (int i = 0; i < n; ++i) {
        if (leaf[i]) parity[depth[i] % 2]++;
    }

    return parity[0] && parity[1];
}

int GetMax() {
    return n - 1 - count(all(leaf), true) + count(all(has_leaf), true);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    Reset();

    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    
    long st = 0;
    for (int i = 0; i < n; ++i) {
        if ((int) g[i].size() > 1) st = i;
    }
    depth[st] = 0;
    Dfs(st);
    
    cout << (CheckMin() ? 3 : 1) << ' ';
    cout << GetMax();
    
    return 0;
}