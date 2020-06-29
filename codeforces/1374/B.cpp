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

// now start
ll constexpr INF = 1e14;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto &&run_case = []() {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "0\n";
            return;
        }
        if (n % 3 != 0) {
            cout << "-1\n";
            return;
        }
        int cnt2 = 0, cnt3 = 0;
        while (!(n & 1)) {
            cnt2++;
            n /= 2;
        }
        while (!(n % 3)) {
            cnt3++;
            n /= 3;
        }
        if (cnt2 > cnt3) {
            cout << "-1\n";
            return;
        }
        if (n != 1) {
            cout << "-1\n";
            return;
        }
        cout << cnt3 + (cnt3 - cnt2) << '\n';
    };

    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}