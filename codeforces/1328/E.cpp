#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 10;

vector<int> g[N];
int p[N], d[N], in[N], out[N], counter;

void dfs(int v) {
    in[v] = counter++;
    for (auto &u : g[v])
        if (p[v] != u) {
            p[u] = v;
            d[u] = d[v] + 1;
            dfs(u);
        }
    out[v] = counter++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    
    p[0] = -1;
    dfs(0);
    
    while (m--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            --a[i];
        }
        sort(begin(a), end(a), [&](auto &lhs, auto &rhs) {
            return d[lhs] < d[rhs];
        });
        reverse(begin(a), end(a));
        
        int last = a[0];
        bool bad = false;
        for (int i = 1; i < k; ++i) {
            if (in[last] >= in[a[i]] && out[last] <= out[a[i]])
                continue;
            int parent = p[a[i]];
            if (parent != -1 && in[last] >= in[parent] && out[last] <= out[parent])
                continue;
            bad = true;
        }

        cout << (bad ? "NO" : "YES") << '\n';
    }

    return 0;
}
