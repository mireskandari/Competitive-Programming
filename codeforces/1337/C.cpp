#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    auto g = new vector<int>[n];
    vector<char> mark(n, false);
    vector<int> cnt(n, 0);
    vector<tuple<int, int>> dep;
    rep (0, n - 1, i) {
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    vector<int> cntc(n, 0);
    function<void(int, int)> Dfs1 = [&](int v, int d) {
        mark[v] = true;
        for (auto u : g[v]) {
            if (!mark[u]) {
                Dfs1(u, d + 1);
                cntc[v] += cntc[u] + 1;
            }
        }
        dep.emplace_back(d - cntc[v], v);
    };
    Dfs1(0, 0);
    sort(all(dep), greater<>());
    vector<char> isind(n, false);
    rep (0, k, i) {
        isind[get<1>(dep[i])] = true;
//        cerr << dep[i].X << ' ';
    }
    fill(all(mark), false);
    vector<ll> happy(n);
    function<void(int, ll)> Dfs2 = [&](int v, ll cnt){
        mark[v] = true;
        happy[v] = cnt;
        bool pl = false;
        if (!isind[v]) pl = true;
        for (auto u : g[v]) {
            if (!mark[u]) {
                Dfs2(u, cnt + pl);
            }
        }
    };
    Dfs2(0, 0);
    ll sum = 0;
    rep (0, n, i) {
        if (isind[i]) sum += happy[i];
    }
    cout << sum;
    return 0;
}