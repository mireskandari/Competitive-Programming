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
    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    rep (0, n, i) cin >> d[i];
    vec<2, int> g(n);
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) { return d[x] < d[y]; });
    vec<2, int> dep(n);
    vector<int> av(n), out(n);
    if (d[id[0]] != 0) {
        cout << -1;
        return 0;
    }
    if (n > 1 && d[id[1]] == 0) {
        cout << -1;
        return 0;
    }
    cerr << id << ' ';
    dep[0].emplace_back(id[0]);
    for (auto &i : id) {
        if (d[i] == 0) continue;
        if (av[d[i] - 1] == size(dep[d[i] - 1])) {
            cout << -1;
            return 0;
        }
        g[dep[d[i] - 1][av[d[i] - 1]]].emplace_back(i);
        out[dep[d[i] - 1][av[d[i] - 1]]]++;
        if (!!(d[i] - 1) == k) {
            cout << -1;
            return 0;
        }
        if (out[dep[d[i] - 1][av[d[i] - 1]]] + (d[i] - 1 != 0) == k) av[d[i] - 1]++;
        dep[d[i]].emplace_back(i);
        cerr << g << '\n' << dep << '\n' << av << '\n' << d[i] << '\n';
    }
    int sz = accumulate(all(g), 0, [&](int s, auto &a) {
        return s + size(a);
    });
    cout << sz << '\n';
    rep (0, n, i) {
        for (auto &u : g[i]) cout << i + 1 << ' ' << u + 1 << '\n';
    }
    return 0;
}