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

template<typename T>
struct Modular {
    long long val;
    static int constexpr mod() { return T::value; };

    Modular(long long v = 0) {
        val = v % mod();
        if (val < 0) val += mod();
    }

    Modular(long long a, long long b) : val(0) {
        *this += a;
        *this /= b;
    }

    Modular &operator+=(Modular const &b) {
        val += b.val;
        if (val >= mod()) val -= mod();
        return *this;
    }

    Modular &operator-=(Modular const &b) {
        val -= b.val;
        if (val < 0) val += mod();
        return *this;
    }

    Modular &operator*=(Modular const &b) {
        val = (long long) val * b.val % mod();
        return *this;
    }

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return mexp(a, mod() - 2);
    }

    Modular &operator/=(Modular const &b) {
        return *this *= inverse(b);
    }

    friend Modular
    operator+(Modular a, Modular const b) { return a += b; }

    friend Modular
    operator-(Modular a, Modular const b) { return a -= b; }

    friend Modular operator-(Modular const a) {
        return 0 - a;
    }

    friend Modular
    operator*(Modular a, Modular const b) { return a *= b; }

    friend Modular
    operator/(Modular a, Modular const b) { return a /= b; }

    friend Modular operator%(Modular a, Modular const b) {
        return a.val %= b.val;
    }

    friend std::ostream &
    operator<<(std::ostream &os, Modular const &a) {
        return os << a.val;
    }

#define IMPLEMENT_COMPARE_OPERATOR(x) \
    friend bool operator x (Modular const& a, Modular const& b) { \
            return a.val x b.val; \
    }

    IMPLEMENT_COMPARE_OPERATOR(<)

    IMPLEMENT_COMPARE_OPERATOR(>)

    IMPLEMENT_COMPARE_OPERATOR(<=)

    IMPLEMENT_COMPARE_OPERATOR(>=)

    IMPLEMENT_COMPARE_OPERATOR(==)

    IMPLEMENT_COMPARE_OPERATOR(!=)
};

//struct VarMod { static int value; };
//int VarMod::value;
//int &MOD = VarMod::value;
//using Mint = Modular<VarMod>;

int constexpr MOD = 998244353;
using Mint = Modular<std::integral_constant<int, MOD>>;

// now start
ll constexpr INF = 1e14;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    vector<int> dig(n);
    vec<2, int> comp_d(n);
    vector<int> cnt_d(13);
    for (auto i : range<>(n)) {
        comp_d[i].emplace_back();
        for (int temp = a[i]; temp > 0; temp /= 10) {
            comp_d[i].emplace_back(temp % 10);
            dig[i]++;
        }
        cnt_d[dig[i]]++;
    }


    vector<int> suf(13), pref(13);
    for (auto i : rrange<>(11, 1)) {
        suf[i] = suf[i + 1] + cnt_d[i];
    }
    for (auto i : range<>(1, 13)) {
        pref[i] = pref[i - 1] + cnt_d[i];
    }

    vector<Mint> tens(31, 1);
    for (auto i : range<>(1, 31)) tens[i] = tens[i - 1] * 10;

    Mint ans = 0;
    for (auto i : range<>(n)) {
        for (auto j : range<>(1, dig[i] + 1)) {
            Mint now = comp_d[i][j];

            ans += Mint(suf[j]) * now * tens[2 * (j - 1)];
            ans += Mint(suf[j]) * now * tens[2 * (j - 1) + 1];

            for (auto x : range<>(1, j)) {
                ans += 2 * Mint(cnt_d[x]) * now * tens[j - 1 + x];
            }
        }
    }

    cout << ans;
    return 0;
}