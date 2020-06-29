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

// magic
template<class T> struct Nit { T _v, _s; Nit(T v, T s) : _v(v), _s(s) {} operator T &() { return _v; } T operator *() const { return _v; } Nit &operator++() { _v += _s; return *this; } bool operator!=(Nit &a) { return (_s > 0 ? _v < a._v : _v >= a._v); } }; template<class T = int> struct range { T _b, _e, _s; range(T e) : _b(0), _e(e), _s(1) {} range(T b, T e, T s = 1) : _b(b), _e(e), _s(s) {} Nit<T> begin() { return Nit<T>(_b, _s); } Nit<T> end() { return Nit<T>(_e, _s); } }; template<class T = int> struct rrange : range<T> { rrange(T e, T b, T s = 1) : range<T>(e, b, -s) {} rrange(T e) : range<T>(e, 0, -1) {} }; template<class T> struct y_res { T t; y_res(T &&t) : t(forward<T>(t)) {} template<class... Args> decltype(auto) operator() (Args &&...args) const { return t(*this, forward<Args>(args)...); } }; template<class T> decltype(auto) y_comb(T &&t) { return y_res<decay_t<T>>(forward<T>(t)); } template<int D, class T> struct vec : public vector<vec<D - 1, T>> { template<class... Args> vec(int n = 0, Args... a) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {} }; template<class T> struct vec<1, T> : public vector<T> { vec(int n = 0, T const &val = T()) : vector<T>(n, val) {} };

template<int N, class T> void print_tuple(ostream &, T const &) {} template<int N, class T, class H, class... Args> void print_tuple(ostream &os, T const &t) { if (N) os << " ,"; os << std::get<N>(t); print_tuple<N + 1, T, Args...>(os, t); } template<class... Args> ostream &operator<<(ostream &os,const tuple<Args...> &t){ os << "{"; print_tuple<0, tuple<Args...>, Args...>(os, t); return os << "}"; } template<class Ch, class Tr, class C> basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, C const &x) { os << "{ "; for (auto &y : x) os << y << " "; return os << "}"; } template<class I, class J> ostream &operator<<(ostream &os, pair<I, J> const &p) { return os << "[ " << p.first << ", " << p.second << " ]"; }


// now start
int constexpr INF = 1e7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> in(n);
    vector<int> alice, bob, both;
    for (auto &i : in) {
        cin >> i[0] >> i[1] >> i[2];
        if (i[1] ^ i[2]) {
            (i[1] ? alice : bob).emplace_back(i[0]);
        } else {
            if (i[1] & i[2]) {
                both.emplace_back(i[0]);
            }
        }
    }

    sort(all(bob), greater<int>());
    sort(all(alice), greater<int>());
    sort(all(both), greater<int>());

    auto &&sz = [&](auto &c) -> int { return c.size(); };

    if (sz(alice) + sz(both) < k || sz(bob) + sz(both) < k) {
        cout << -1;
        return 0;
    }

    int cnt = 0;
    ll time = 0;
    while (cnt < k) {
        cerr << alice << ' ' << bob << ' ' << both << '\n';

        int aback, bback, cback;
        if(!alice.empty()) {
            aback = alice.back();
        } else aback = INF;

        if(!bob.empty()) {
            bback = bob.back();
        } else bback = INF;

        if(!both.empty()) {
            cback = both.back();
        } else cback = INF;

        if (aback + bback <= cback) {
            time += (aback != INF ? aback : 0) + (bback != INF ? bback : 0);
            if (!alice.empty()) alice.pop_back();
            if (!bob.empty()) bob.pop_back();
        } else {
            time += (cback != INF ? cback : 0);
            if (!both.empty()) both.pop_back();
        }
        cnt++;
    }

    cout << time;
    return 0;
}