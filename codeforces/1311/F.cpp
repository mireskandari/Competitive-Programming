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
inline int constexpr size(T& cont) {
    return cont.size();
}
/* </not-serious> */

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T, class Comp = less<T>>
using pbds = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

ll constexpr INF = 1e18;


template<class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, Container const &x) {
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
    return os << "[ " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << " ]";
}

template<class A, class B, class C, class D>
ostream &operator<<(ostream &os, tuple<A, B, C, D> const &t) {
    return os << "[ " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ", " << get<3>(t) << " ]";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& i : a) cin >> i.X;
    for (auto& i : a) cin >> i.Y;
    sort(all(a));
    pbds<ll, less_equal<>> vs;
    ll ans = 0;
    for (auto i : range(n)) {
//        cerr << ans << ' ' << a[i].Y << ' ' << vs.order_of_key(a[i].Y + 1) << ' ' << vs << '\n';
        ans += a[i].X * vs.order_of_key(a[i].Y + 1);
        vs.insert(a[i].Y);
    }
    vector<ll> pre(n);
    pbds<ll, greater_equal<>> v;
    for (auto i : rrange(n - 1)) {
//        cerr << ans << ' ' << a[i].Y << ' ' << v.order_of_key(a[i].Y) << ' ' << v << '\n';
        ans -= a[i].X * v.order_of_key(a[i].Y - 1);
        v.insert(a[i].Y);
    }
    cout << ans;
    return 0;
}