#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

using ll = long long;
using ld = long double;

#define reps(a, b, x, s) \
        for (decay<decltype(b)>::type x = a; x < b; x += s)
#define pers(b, a, x, s) \
        for (decay<decltype(b)>::type x = b; x >= a; x -= s)

#define rep(a, b, x) reps(a, b, x, 1)
#define per(b, a, x) pers(b, a, x, 1)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

template<class C>
inline int constexpr __size(C c) { return c.size(); }
#define size __size

template<int D, class T>
struct vec : public vector<vec<D - 1, T>> {
    template <class... Args>
    vec(int n = 0, Args... a) :
        vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {}
};

template<typename T>
struct vec<1, T> : public vector<T> {
    vec(int n = 0, T const &val = T()) :
    vector<T>(n, val) {}
};


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


template<class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr> &os,
                Container const &x) {
    os << "{ ";
    for (auto &y : x) os << y << " ";
    return os << "}";
}

template<class X, class Y>
ostream& operator<<(ostream &os, pair<X, Y> const &p) {
    return os << "[ " << p.first << ", " << p.second << " ]";
}

template<class Ch, class Tr, class Tuple, int N>
struct Tp {
    static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {
        Tp<Ch, Tr, Tuple, N - 1>::print(os, t);
        os << std::get<N - 1>(t) << " ";
    }
};

template<class Ch, class Tr, class Tuple>
struct Tp<Ch, Tr, Tuple, 0> {
    static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {}
};

template<class Ch, class Tr, class... Args>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr> &os,
                tuple<Args...> const &t) {
    os << "[ ";
    Tp<Ch, Tr, tuple<Args...>, sizeof...(Args)>::print(os, t);
    return os << "]";
}

// now start

ll const INF = 1e14;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (m > n) {
        cout << 0;
        return 0;
    }
    vector<int> a(n), b(m);
    rep (0, n, i) cin >> a[i];
    rep (0, m, i) cin >> b[i];
    vector<int> mn(m), last(m);
    int now = m - 1;
    per (n - 1, 0, i) {
        if (a[i] < b[now]) {
            mn[now--] = i + 1;
        }
        if (now < 0) break;
    }
    now = m - 1;
    per (n - 1, 0, i) {
        if (a[i] == b[now]) last[now--] = i;
        if (now < 0) break;
    }
    if (mn[0] != 0) {
        cout << 0;
        return 0;
    }
    rep (0, n, i) {
        if (a[i] == b[0]) break;
        if (a[i] < b[0]) {
            cout << 0;
            cerr << 1;
            return 0;
        }
    }
    per (n - 1, 0, i) {
        if (a[i] == b.back()) break;
        if (a[i] < b.back()) {
            cout << 0;
            cerr << 2;
            return 0;
        }
    }
    rep (0, m - 1, i) {
        rep (last[i] + 1, mn[i + 1], j) {
            if (a[j] < b[i]) {
                cout << 0;
                return 0;
            }
        }
    }
    set<int> check(all(a));
    rep (0, m, i) {
        if (!check.count(b[i])) {
            cout << 0;
            return 0;
        }
    }
    Mint ans = 1;
    rep (1, m, i) {
        ans *= (last[i] - mn[i] + 1);
    }
    cerr << mn << ' ' << last << '\n';
    cout << ans;
    return 0;
}
