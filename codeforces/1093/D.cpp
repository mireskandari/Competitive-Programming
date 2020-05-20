#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
#define Len(x) (static_cast<int>((x).size()))

/* <not-serious> */
template<typename T>
class number_iterator : iterator<forward_iterator_tag, T> {
public:
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
private:
    T v, step;
};

template<typename T = int>
class range : pair<T, T> {
public:
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
private:
    T step;
    T _end(T begin, T end, T _step) {
        return _step > 0 ? max(begin, end) : min(begin, end - 1);
    }
};

template<typename T = int>
class rrange : public range<T> {
public:
    rrange(T end, T begin) : range<T>(end, begin, -1) {}
    rrange(T end) : range<T>(end, 0, -1) {}
};

template<class T = int, class... Args>
auto vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, T(args...));
    else
        return vector(n, vec<T>(args...));
}
/* </not-serious> */
int constexpr MOD = 998244353;
ll constexpr INF = 1e9;

template <int MOD>
struct Modular {
    int val;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { val = v % MOD; if (val < 0) val += MOD;}
    Modular(long long a, long long b) : val(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {val += b.val; if (val >= MOD) val -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {val -= b.val; if (val < 0) val += MOD;return *this;}
    Modular& operator*=(Modular const& b) {val = (long long)val * b.val % MOD;return *this;}

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend Modular mexp(long long a, long long e) { return mexp(Modular(a), e); }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }
    friend Modular inverse(long long a) { return mexp(Modular(a), MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.val;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.val == b.val;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.val != b.val;}
};
using Mint = Modular<MOD>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<char> mk(n, false), col(n);
        vector<int> d(n);
        auto g = new vector<int>[n];
        for (auto i : range(m)) {
            int v, u;
            cin >> v >> u;
            g[--v].emplace_back(--u);
            g[u].emplace_back(v);
        }
        static auto Dfs = [&](auto& F, int v,
                ll& a, ll& b) -> bool {

            (col[v] ? a : b)++;
            mk[v] = true;
            for (auto u : g[v]) {
                if (mk[u] && (d[u] - d[v]) % 2 == 0 && col[v] == col[u]) {
                    return false;
                }
            }
            for (auto u : g[v]) {
                if (!mk[u]) {
                    d[u] = d[v] + 1;
                    col[u] = !col[v];
                    if(!F(F, u, a, b)) return false;
                }
            }
            return true;
        };
        Mint ans = 1;
        for (auto i : range(n)) {
            if (!mk[i]) {
                d[i] = 0;
                col[i] = false;
                ll a = 0, b = 0;
                if (!Dfs(Dfs, i, a, b)) ans = 0;
                else ans *= mexp(Mint(2), a) + mexp(Mint(2), b);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}