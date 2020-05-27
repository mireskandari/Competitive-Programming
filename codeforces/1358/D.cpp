// restrained.
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

/* <not-serious> */
template<typename T>
struct number_iterator :
        iterator<forward_iterator_tag, T> {
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
        return _step > 0 ? max(begin, end) :
               min(begin, end - 1);
    }
    using ptt = pair<T, T>;
    range(T begin, T end) : ptt(begin, max(begin, end)),
                            step(1) {}
    range(T end) : ptt(0, max<T>(0, end)), step(1) {}
    range(T begin, T end, T _step) :
            ptt(begin, _end(begin, end, _step)),
            step(_step) {}
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

template<class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &
operator<<(basic_ostream<Ch, Tr> &os, Container const &x) {
    os << "{ ";
    for (auto &y : x) os << y << " ";
    return os << "}";
}

template<class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p) {
    return os << "[ " << p.first << ", " << p.second << "]";
}

template<class A, class B, class C>
ostream &operator<<(ostream &os, tuple<A, B, C> const &t) {
    return os << "[ " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t)
              << " ]";
}

template<class A, class B, class C, class D>
ostream &operator<<(ostream &os, tuple<A, B, C, D> const &t) {
    return os << "[ " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t)
              << ", " << get<3>(t) << " ]";
}

ll constexpr INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(2 * n);
    for (auto i : range(n)) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    reverse(all(a));
    vector<ll> pref(2 * n);
    vector<ll> sum(2 * n);
    auto Sum = [](ll n) {
        return (n + 1) * n / 2;
    };
    for (auto i : range(2 * n)) {
        pref[i] = a[i] + (i == 0 ? 0 : pref[i - 1]);
        sum[i] = Sum(a[i]) + (i == 0 ? 0 : sum[i - 1]);
    }
//    cerr << pref << '\n';
    ll mx = -INF;
    for (auto i : range(n)) {
        int p = upper_bound(all(pref), x + (i == 0 ? 0 : pref[i - 1])) -
                pref.begin();
//        cerr << x + (i == 0 ? 0 : pref[i - 1]) << ' ' << a[i] << ' ' << pref[i] << ' ' << p << ' ' << pref[p] - (i == 0 ? 0 : pref[i - 1]) << '\n';
        ll ans, rmans;
        if (p == i) {
            ans = 0;
            rmans = Sum(a[i]) - Sum(a[i] - x);
        } else {
            p--;
            ll passed = pref[p] - (i == 0 ? 0 : pref[i - 1]);
//            cerr << passed << ' ';
            ans = sum[p] - (i == 0 ? 0 : sum[i - 1]);
            p++;
//            cerr << a[p] << '\n';
            rmans = Sum(a[p]) - Sum(a[p] - x + passed);
        }
        mx = max(ans + rmans, mx);
    }
    cout << mx;
    return 0;
}