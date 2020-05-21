//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target ("sse4.2")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

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
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e18;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, A, R, M;
    cin >> n >> A >> R >> M;
    M = min(A + R, M);
    vector<ll> a(n);
    for (auto i : range(n)) cin >> a[i];
    sort(all(a));
    vector<ll> pre(n), suf(n);
    partial_sum(all(a), pre.begin());
    partial_sum(rall(a), suf.rbegin());
    auto Solve = [&](ll h) -> ll {
        ll i = upper_bound(all(a), h) - a.begin();
        ll l = i == 0 ? 0 : i * h - pre[i - 1];
        ll r = i == n ? 0 : suf[i] - (n - i) * h;
//        cerr << l << ' ' << r << ' ' << h << '\n';
        return l > r ? A * (l - r) + M * r : R * (r - l) + M * l;
    };
    ll l = 0, r = 1e9;
    while (true) {
        ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (m1 == l || m2 == r) break;
        if (Solve(m1) > Solve(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    ll ans = INF;
    for (auto i : range(l, r + 1)) {
        ans = min(ans, Solve(i));
    }
    cout << ans;
    return 0;
}