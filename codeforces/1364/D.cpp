#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

using ll = long long;
using ld = long double;

#define reps(a, b, x, s) for (decay<decltype((b))>::type x = (a); (x) < (b); (x) += (s))
#define pers(b, a, x, s) for (decay<decltype((b))>::type x = (b); (x) >= (a); (x) -= (s))
#define rep(a, b, x) for (decay<decltype((b))>::type x = (a); (x) < (b); ++(x))
#define per(b, a, x) for (decay<decltype((b))>::type x = (b); (x) >= (a); --(x))
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

template<int D, class T>
struct vec : public vector<vec<D - 1, T>> { template<class... Args> vec(int n = 0, Args... a) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {} };
template<class T> struct vec<1, T> : public vector<T> { vec(int n = 0, T const &val = T()) : vector<T>(n, val) {} };


template<int N, class T> void print_tuple(ostream &, T const &) { }
template<int N, class T, class H, class... Args> void print_tuple(ostream &os, T const &t) { if (N) os << " ,"; os << std::get<N>(t); print_tuple<N + 1, T, Args...>(os, t); }
template<class... Args> ostream &operator<<(ostream &os,const tuple<Args...> &t){ os << "{"; print_tuple<0, tuple<Args...>, Args...>(os, t); return os << "}"; }
template<class Ch, class Tr, class C> basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, C const &x) { os << "{ "; for (auto &y : x) os << y << " "; return os << "}"; }
template<class I, class J> ostream &operator<<(ostream &os, pair<I, J> const &p) { return os << "[ " << p.first << ", " << p.second << " ]"; }

// now start
ll const INF = 1e14;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vec<2, int> g(n);
    rep (0, m, i) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    vector<int> col(n, 0);
    auto &&dfs = [&](auto &f, int v) -> void {
        for (auto &u : g[v]) if (!col[u]) {
            col[u] = 3 - col[v];
            f(f, u);
        }
    };
    if (m == n - 1) {
        vector<int> c1, c2;
        col[0] = 1;
        dfs(dfs, 0);
        rep (0, n, i) {
            (col[i] == 1 ? c1 : c2).emplace_back(i);
        }
        if (size(c1) < size(c2)) swap(c1, c2);
        cout << 1 << '\n';
        cerr << c1 << ' ' << c2 << ' ' << col << '\n';
        rep (0, (k + 1) / 2, i) cout << c1[i] + 1 << ' ';
        return 0;
    }
    vector<int> d(n), mark(n), p(n);
    auto &&dfs1 = [&](auto &f, int v) -> void {
        mark[v] = true;
        for (auto &u : g[v]) {
            if (mark[u] && p[v] != u) {
                cerr << 12344 << d[v] << ' ' << d[u] << ' ' << v << ' ' << u << '\n';
                if (d[v] - d[u] < k) {
                    cout << "2\n" << d[v] - d[u] + 1 << '\n';
                    while (v != u) {
                        cout << v + 1 << ' ';
                        v = p[v];
                    }
                    cout << u + 1;
                    exit(0);
                }
            }
        }
        for (auto &u : g[v]) {
            if (!mark[u]) {
                p[u] = v;
                d[u] = d[v] + 1;
                f(f, u);
            }
        }
    };
    p[0] = -1;
    dfs1(dfs1, 0);
    vector<int> cycle;
    tuple<int, int, int> fnd = {-1, -1, -1};
    auto &&dfs2 = [&](auto &f, int v) -> void {
        mark[v] = true;
        for (auto &u : g[v]) {
            if (mark[u] && p[v] != u) {
                if (get<2>(fnd) < d[v] - d[u]) {
                    fnd = {v, u, d[v] - d[u]};
                    cerr << fnd;
                }
            }
        }
        for (auto &u : g[v]) {
            if (!mark[u]) {
                p[u] = v;
                d[u] = d[v] + 1;
                f(f, u);
            }
        }
    };
    fill(all(mark), false);
    dfs2(dfs2, 0);
    int v, u;
    tie(v, u, ignore) = fnd;
    while (u != v) {
        cycle.emplace_back(v);
        v = p[v];
    }
    cycle.emplace_back(u);
    vector<int> in1, in2, mk1(n), mk2(n);
    cerr << cycle << ' ';
    for (auto &v : cycle) {
        if (!mk1[v]) {
            cerr << v << ' ';
            in1.emplace_back(v);
            mk2[v] = true;
            for (auto &u : g[v]) mk1[u] = true;
        }
    }
    for (auto &v : cycle) {
        if (!mk2[v]) {
            in2.emplace_back(v);
            for (auto &u : g[v]) mk2[u] = true;
        }
    }
    if (size(in1) < size(in2)) swap(in1, in2);
    assert(size(in1) >= (k + 1) / 2);
    cout << "1\n";
    rep (0, (k + 1) / 2, i) cout << in1[i] + 1 << ' ';
    return 0;
}