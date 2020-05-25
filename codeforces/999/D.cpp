#include <bits/stdc++.h>
#define int long long
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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<vector<int>> cnt(m);
    for (auto i : range(n)) cnt[a[i] % m].emplace_back(i);
    int d = n / m;
    deque<int> pos;
    multiset<int> neg;
    for (auto i : range(m)) {
        while (size(cnt[i]) > d) {
            pos.emplace_back(cnt[i].back());
            cnt[i].pop_back();
        }
        for (auto _ : range(size(cnt[i]), d)) {
            neg.emplace(i);
        }
    }
    if (pos.empty()) {
        cout << "0\n";
        for (auto &i : a) cout << i << ' ';
        return 0;
    }
    auto FindNear = [](int a, int mod, int m) -> pair<int, int> {
//        cerr << a << ' ' << mod << ' ' << m << '\n';
        if (a % m == mod) return {a, 0};
        int d = mod - a % m;
        if (d > 0) return {a + d, d};
        else return {a + m - abs(d), m - abs(d)};
    };
//    auto Solve = [&](int s) {
//        int delta = 0;
////        cerr << s << '\n';
//        deque<int> temp(all(neg));
//        rotate(temp.begin(), temp.begin() + s, temp.end());
//        for (auto i : range(size(pos))) {
//            delta += FindNear(a[pos[i]], temp[i], m).Y;
//        }
//        return delta;
//    };
//    for (auto i : range(size(pos))) {
//        cerr << Solve(i) << ' ';
//    }
//    int l = 0, r = size(pos) - 1;
//    while (true) {
//        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
//        if (m1 == l || m2 == r) break;
//        if (Solve(m1) > Solve(m2)) {
//            l = m1;
//        } else {
//            r = m2;
//        }
//    }
//    int j = Solve(l) < Solve(r) ? l : r;
//    for (auto i : range(j)) {
//        pos.emplace_back(pos.front());
//        pos.pop_front();
//    }
    int delta = 0;
    while (!pos.empty()) {
        auto p = neg.lower_bound(a[pos.front()] % m);
        if (p == neg.end()) p = neg.begin();
        auto ans = FindNear(a[pos.front()], *p, m);
//        cerr << ans.X << ' ' << ans.Y << '\n';
        a[pos.front()] = ans.X;
        delta += ans.Y;
        pos.pop_front();
        neg.erase(p);
    }
    cout << delta << '\n';
    for (auto &i : a) cout << i << ' ';
    return 0;
}