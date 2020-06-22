#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

using ll = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

template<class T> struct Nit { T _v, _s; Nit(T v, T s) : _v(v), _s(s) {} operator T &() { return _v; } T operator *() const { return _v; } Nit &operator++() { _v += _s; return *this; } bool operator!=(Nit &a) { return (_s > 0 ? _v < a._v : _v >= a._v);} };
template<class T = int> struct range { T _b, _e, _s; range(T e) : _b(0), _e(e), _s(1) {} range(T b, T e, T s = 1) : _b(b), _e(e), _s(s) {} Nit<T> begin() { return Nit<T>(_b, _s); } Nit<T> end() { return Nit<T>(_e, _s); } };
template<class T = int> struct rrange : range<T> { rrange(T e, T b, T s = 1) : range<T>(e, b, -s) {} rrange(T e) : range<T>(e, 0, -1) {} };

template<int D, class T> struct vec : public vector<vec<D - 1, T>> { template<class... Args> vec(int n = 0, Args... a) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {} };
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &i : a) cin >> i;
    ll init = 0;
    for (auto i : range<>(m - 1)) {
        init += abs(a[i] - a[i + 1]);
    }
    vec<2, int> adj(n + 1);
    vector<int> cntless(n + 2), cntgreat(n + 2);
    for (auto i : range<>(m - 1)) {
        cntless[max(a[i], a[i + 1]) + 1]++;
        cntgreat[min(a[i], a[i + 1]) - 1]++;
        adj[a[i]].emplace_back(a[i + 1]);
        if (a[i + 1] != a[i]) {
            adj[a[i + 1]].emplace_back(a[i]);
        }
    }
    for (auto i : range<>(1, n + 2)) {
        cntless[i] += cntless[i - 1];
    }
    for (auto i : rrange<>(n)) {
        cntgreat[i] += cntgreat[i + 1];
    }
    cout << init << ' ';
    for (auto i : range<>(2, n + 1)) {
        ll res = init;
        for (auto &j : adj[i]) {
            if (j == i) continue;
            res -= abs(i - j);
            res += (j < i ? j : j - 1);
        }
        int cntbetween = m - 1 - cntless[i] - cntgreat[i] - adj[i].size();
        cerr << cntless[i] << ' ' << cntgreat[i] << ' ' << cntbetween << ' ' << adj[i] << ' ' << res << '\n';
        res -= cntbetween;
        cout << res << ' ';
    }

    return 0;
}