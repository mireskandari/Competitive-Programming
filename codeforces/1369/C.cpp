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


// now start
ll const INF = 1e14;

void run_case() {
    int n, k;
    cin >> n >> k;
    deque<int> a(n);
    for (auto &i : a) cin >> i;
    deque<int> w(k);
    for (auto &i : w) cin >> i;

    sort(all(w));
    sort(all(a), greater<int>());

    ll res = 0;
    while (!w.empty() && w.front() == 1) {
        res += a.front() * 2;
        a.pop_front();
        w.pop_front();
    }

    sort(all(w), greater<int>());

    while (!w.empty()) {
        res += a.front();
        a.pop_front();
        res += a.back();
        a.pop_back();
        w.front() -= 2;
        while (w.front() > 0) {
            a.pop_back();
            w.front()--;
        }
        w.pop_front();
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}