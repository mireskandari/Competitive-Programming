#pragma GCC optimize ("O0")
#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

using ll = unsigned long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

// magic
template<class T> struct Nit { T _v, _s; Nit(T v, T s) : _v(v), _s(s) {} operator T &() { return _v; } T operator *() const { return _v; } Nit &operator++() { _v += _s; return *this; } bool operator!=(Nit &a) { return (_s > 0 ? _v < a._v : _v >= a._v); } }; template<class T = int> struct range { T _b, _e, _s; range(T e) : _b(0), _e(e), _s(1) {} range(T b, T e, T s = 1) : _b(b), _e(e), _s(s) {} Nit<T> begin() { return Nit<T>(_b, _s); } Nit<T> end() { return Nit<T>(_e, _s); } }; template<class T = int> struct rrange : range<T> { rrange(T e, T b, T s = 1) : range<T>(e, b, -s) {} rrange(T e) : range<T>(e, 0, -1) {} };  template<int D, class T> struct vec : public vector<vec<D - 1, T>> { template<class... Args> vec(int n = 0, Args... a) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {} }; template<class T> struct vec<1, T> : public vector<T> { vec(int n = 0, T const &val = T()) : vector<T>(n, val) {} };
//source : Benq
ll const MOD = 1e9 + 7; struct Mint { typedef decay<decltype(MOD)>::type T; T v; explicit operator T() const { return v; } Mint() { v = 0; } Mint(long long _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD; } friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; } friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); } friend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; } friend string to_string(Mint a) { return to_string(a.v); } friend ostream &operator<< (ostream& os, Mint &a) { return os << to_string(a); } Mint &operator+=(const Mint &m) { if ((v += m.v) >= MOD) v -= MOD; return *this; } Mint &operator-=(const Mint &m) { if ((v -= m.v) < 0) v += MOD; return *this; } Mint &operator*=(const Mint &m) { v = (long long) v * m.v % MOD; return *this; } Mint &operator/=(const Mint &m) { return (*this) *= inv(m); } friend Mint pow(Mint a, long long p) { Mint ans = 1; assert(p >= 0); for (; p; p /= 2, a *= a) if (p & 1) ans *= a; return ans; } friend Mint inv(const Mint &a) { assert(a.v != 0); return pow(a, MOD - 2); } Mint operator-() const { return Mint(-v); } Mint &operator++() { return *this += 1; } Mint &operator--() { return *this -= 1; } friend Mint operator+(Mint a, const Mint &b) { return a += b; } friend Mint operator-(Mint a, const Mint &b) { return a -= b; } friend Mint operator*(Mint a, const Mint &b) { return a *= b; } friend Mint operator/(Mint a, const Mint &b) { return a /= b; } };
template<int N, class T> void print_tuple(ostream &, T const &) {} template<int N, class T, class H, class... Args> void print_tuple(ostream &os, T const &t) { if (N) os << " ,"; os << std::get<N>(t); print_tuple<N + 1, T, Args...>(os, t); } template<class... Args> ostream &operator<<(ostream &os,const tuple<Args...> &t){ os << "{"; print_tuple<0, tuple<Args...>, Args...>(os, t); return os << "}"; } template<class Ch, class Tr, class C> basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, C const &x) { os << "{ "; for (auto &y : x) os << y << " "; return os << "}"; } template<class I, class J> ostream &operator<<(ostream &os, pair<I, J> const &p) { return os << "[ " << p.first << ", " << p.second << " ]"; }

// now start
ll constexpr INF = 1e14;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, n;
    cin >> x >> n;

    set<ll> pr;
    for (auto i : range<ll>(2, (ll) sqrt(x) + 1)) {
        if (x % i == 0){
            pr.emplace(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) pr.emplace(x);

    Mint ans = 1;
    for (auto &p : pr) {
        ll now = p;
        while (n / now > 0) {
            ans *= pow(Mint(p), n / now);
            if ((now * p) / p != now) break;
            now *= p;
        }
    }
    cout << ans;
    return 0;
}