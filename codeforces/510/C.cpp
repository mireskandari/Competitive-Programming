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

int constexpr A = 26;

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    vector<string> a(n); for (auto &i : a) cin >> i;
    vector<vector<int>> g(A);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int len = (int) min(a[i].size(), a[j].size());
            int x = 0;
            while (x < len && a[i][x] == a[j][x]) ++x;
            if (x >= (int) a[i].size() || x >= (int) a[j].size()) {
                if (a[i].size() > a[j].size()) {
                    cout << "Impossible";
                    exit(0);
                }
                continue;
            }
            g[a[i][x] - 'a'].emplace_back(a[j][x] - 'a');
        }
    }
    vector<int8_t> mark(A);
    vector<int> topo; topo.reserve(A);
    function<void(int)> dfs = [&](int v) {
        mark[v] = 1;
        for (auto &u : g[v]) {
            if (mark[u] == 1) {
                cout << "Impossible";
                exit(0);
            } else if (mark[u] == 0) {
                dfs(u);
            }
        }
        mark[v] = 2;
        topo.emplace_back(v);
    };
    for (int i = 0; i < A; ++i) {
        if (mark[i] == 0) {
            dfs(i);
        }
    }
    reverse(all(topo));
    for (auto &i : topo) {
        cout << (char) (i + 'a');
    }
    return 0;
}
