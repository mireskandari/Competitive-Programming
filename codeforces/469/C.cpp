#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

/* <not-serious> */
template<class T>
struct Nit {
    T _v, _s;
    Nit(T v, T s) : _v(v), _s(s) {}
    operator T &() { return _v; }
    T operator *() const { return _v; }
    Nit &operator++() { _v += _s; return *this; }
    bool operator!=(Nit &a) {
        return (_s > 0 ? _v < a._v : _v >= a._v);
    }
};

template<class T = int>
struct range {
    T _b, _e, _s;
    range(T e) : _b(0), _e(e), _s(1) {}
    range(T b, T e, T s = 1) : _b(b), _e(e), _s(s) {}
    Nit<T> begin() { return Nit<T>(_b, _s); }
    Nit<T> end() { return Nit<T>(_e, _s); }
};

template<class T = int>
struct rrange : range<T> {
    rrange(T e, T b, T s = 1) : range<T>(e, b, -s) {}
    rrange(T e) : range<T>(e, 0, -1) {}
};

template<int D, class T>
struct vec : public vector<vec<D - 1, T>> {
    template<class... Args>
    vec(int n = 0, Args... a) :
    vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {}
};

template<class T>
struct vec<1, T> : public vector<T> {
    vec(int n = 0, T const &v = T()) :
    vector<T>(n, v) {}
};

template<class T>
inline int constexpr size(T &cont) {
    return cont.size();
}
/* </not-serious> */



ll constexpr INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n < 4) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n == 5) {
        cout << "5 + 3 = 8\n"
                "8 + 4 = 12\n"
                "12 * 2 = 24\n"
                "1 * 24 = 24";
        return 0;
    }
    cout << "2 * 3 = 6\n"
            "4 * 6 = 24\n";
    if (n == 4) {
        cout << "1 * 24 = 24";
        return 0;
    }
    cout << "6 - 5 = 1\n"
            "1 - 1 = 0\n";
    for (auto i : range(7, n + 1)) {
        cout << "0 * " << i << " = 0\n";
    }
    cout << "0 + 24 = 24";
    return 0;
}

