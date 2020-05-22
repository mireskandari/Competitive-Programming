#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

/* <not-serious> */
template<typename T>
struct number_iterator : iterator<forward_iterator_tag, T> {
    T v, step;

    number_iterator(T _v) : v(_v), step(1) {}

    number_iterator(T _v, T _step) : v(_v), step(_step) {}

    operator T &() { return v; }

    T operator*() const { return v; }

    number_iterator operator++() {
        v += step;
        return *this;
    }

    bool operator!=(number_iterator rhs) {
        return step > 0 ? v < rhs.v : v > rhs.v;
    }
};

template<typename T = int>
struct range : pair<T, T> {
    T step;

    T _end(T begin, T end, T _step) {
        return _step > 0 ? max(begin, end) : min(begin, end - 1);
    }

    using ptt = pair<T, T>;

    range(T begin, T end) : ptt(begin, max(begin, end)), step(1) {}

    range(T end) : ptt(0, max<T>(0, end)), step(1) {}

    range(T begin, T end, T _step) :
            ptt(begin, _end(begin, end, _step)), step(_step) {}

    number_iterator<T> begin() const {
        return number_iterator<T>(this->first, step);
    }

    number_iterator<T> end() const {
        return number_iterator<T>(this->second, step);
    }
};

template<typename T = int>
struct rrange : range<T> {
    rrange(T end, T begin) : range<T>(end, begin, -1) {}

    rrange(T end) : range<T>(end, 0, -1) {}
};

#if __cplusplus >= 201703L

template<class T = int, class... Args>
auto vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, T(args...));
    else
        return vector(n, vec<T>(args...));
}

#else
template<int D, typename T>
struct vec : public vector<vec<D - 1, T>> {
    template<typename... Args>
    vec(int n = 0, Args... args) :
    vector<vec<D - 1, T>>(n, vec <D - 1, T>(args...)) {}
};

template<typename T>
struct vec<1, T> : public vector<T> {
    vec(int n = 0, const T &val = T()) :
    vector<T>(n, val) {}
};
#endif

template<typename T>
inline int constexpr size(T &cont) {
    return cont.size();
}

/* </not-serious> */


template<typename T>
struct Modular {
    int val;
    static const int MOD = T::value;

    Modular(long long v = 0) {
        val = v % MOD;
        if (val < 0) val += MOD;
    }

    Modular(long long a, long long b) : val(0) {
        *this += a;
        *this /= b;
    }

    Modular &operator+=(Modular const &b) {
        val += b.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    Modular &operator-=(Modular const &b) {
        val -= b.val;
        if (val < 0) val += MOD;
        return *this;
    }

    Modular &operator*=(Modular const &b) {
        val = (long long) val * b.val % MOD;
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

    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular &operator/=(Modular const &b) { return *this *= inverse(b); }

    friend Modular operator+(Modular a, Modular const b) { return a += b; }

    friend Modular operator-(Modular a, Modular const b) { return a -= b; }

    friend Modular operator-(Modular const a) { return 0 - a; }

    friend Modular operator*(Modular a, Modular const b) { return a *= b; }

    friend Modular operator/(Modular a, Modular const b) { return a /= b; }

    friend Modular operator%(Modular a, Modular const b) { return a.val %= b.val; }

    friend std::ostream &operator<<(std::ostream &os, Modular const &a) { return os << a.val; }

#define IMPLEMENT_COMPARE_OPERATOR(x) \
    friend bool operator x (Modular const& a, Modular const& b) { return a.val x b.val; }

    IMPLEMENT_COMPARE_OPERATOR(<)  IMPLEMENT_COMPARE_OPERATOR(>)

    IMPLEMENT_COMPARE_OPERATOR(<=) IMPLEMENT_COMPARE_OPERATOR(>=)

    IMPLEMENT_COMPARE_OPERATOR(==) IMPLEMENT_COMPARE_OPERATOR(!=)
};

// struct VarMod { static int value; };
// int VarMod::value;
// int& MOD = VarMod::value;
// using Mint = Modular<VarMod>;

int constexpr MOD = 1e9 + 7;
using Mint = Modular<integral_constant<int, MOD>>;


ll constexpr INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> in(n), g(n);
    for (auto i : range(n)) {
        int v;
        cin >> v;
        g[i] = --v;
        in[v]++;
    }
    if (count(all(in), 0)) {
        cout << -1;
        return 0;
    }
    set<int> s;
    vector<char> mark(n, false);
    auto Dfs = [&](auto& F, int v) -> int {
        mark[v] = true;
        int d = 0;
        if (!mark[g[v]]) d += F(F, g[v]) + 1;
        return d;
    };
    for (auto i : range(n)) {
        if (!mark[i]) {
            int len = Dfs(Dfs, i) + 1;
            s.emplace(len & 1 ? len : len / 2);
        }
    }
    int const MAX = 5e6 + 10;
    vector<int> spf(MAX, -1);
    for (auto i : range(2, MAX)) {
        if (spf[i] == -1) {
            spf[i] = i;
            for (auto j : range(2 * i, MAX, i)) {
                if (spf[j] == -1) spf[j] = i;
            }
        }
    }
    vector<int> best(MAX);
    for (auto i : s) {
        map<int, int> cnt;
        while (i > 1) {
            cnt[spf[i]]++;
            best[spf[i]] = max(best[spf[i]], cnt[spf[i]]);
            i /= spf[i];
        }
    }
    Mint ans = 1;
    for (auto i : range(1, MAX)) {
        ans *= mexp(Mint(i), best[i]);
    }
    cout << ans;
    return 0;
}