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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    vector<int> c1, c2;
    for (auto i : range<>(n - 1)) {
        if (i & 1) {
            c1.emplace_back(a[i] - a[i + 1]);
        } else {
            c2.emplace_back(a[i + 1] - a[i]);
        }
    }

    auto &&max_sub = [&](vector<int> &v) {
        if (v.empty()) return 0LL;
        ll ans = v[0], sum = 0;
        for (auto i : range<>((int) v.size())) {
            sum += v[i];
            ans = max<ll>(ans, sum);
            sum = max<ll>(sum, 0);
        }
        return ans;
    };

    ll best = max(max_sub(c1), max_sub(c2));
    ll sum = 0;
    for (auto i : range<>(0, n, 2)) {
        cerr << i << ' ';
        sum += a[i];
    }
    cerr << '\n';
    cout << sum + max(0LL, best) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}