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
using vll = vector<long>;
using vi = vector<int>;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    long n; cin >> n;
    vector<vll> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    vector<bool> leaf(n), has_leaf(n);
    long st = 0;
    for (int i = 0; i < n; ++i) {
        if ((int) g[i].size() <= 1) {
            leaf[i] = true;
            has_leaf[g[i][0]] = true;
        } else {
            st = i;
        }
    }
    vector<bool> mark(n);
    vll depth(n);
    function<void(int)> Dfs = [&](int v) {
        mark[v] = true;
        for (auto &u : g[v]) {
            if (!mark[u]) {
                depth[u] = depth[v] + 1;
                Dfs(u);
            }
        }
    };
    Dfs(st);
    long cntl = (int) count(all(leaf), true);
    long cntnl = (int) count(all(has_leaf), true);
    vll parity(2);
    for (int i = 0; i < n; ++i) {
        if (leaf[i]) {
            parity[depth[i] % 2]++;
        }
    }
    cout << (parity[0] > 0 && parity[1] > 0 ? 3 : 1);
    cout << ' ' << n - 1 - cntl + cntnl;
    // what the fuck
    return 0;
}
