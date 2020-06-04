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
    int tc;
    cin >> tc;
    while (tc--) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == b) {
            cout << "0\n";
            continue;
        }
        if (b % a) {
            cout << "-1\n";
            continue;
        }
        ll res = b / a;
        if (res % 2) {
            cout << "-1\n";
            continue;
        }

        ll pos = 0;
        ll cnt = 0;
        ll i = 1;
        res >>= 1;
        while (res > 0) {
            if (res % 2) {
                pos = i;
                cnt++;
            }
            res >>= 1;
            i++;
        }
        cerr << cnt << ' ' << pos << '\n';
        if (cnt > 1) {
            cout << "-1\n";
            continue;
        }
        ll ans = pos / 3;
        pos %= 3;
        ans += pos /2;
        pos %= 2;
        ans += pos;
        cout << ans << '\n';
    }
    return 0;
}

