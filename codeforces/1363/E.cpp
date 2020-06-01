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
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr> &os,
                Container const &x) {
    os << "{ ";
    for (auto &y : x) os << y << " ";
    return os << "}";
}

template<class X, class Y>
ostream& operator<<(ostream &os, pair<X, Y> const &p) {
    return os << "[ " << p.first << ", " << p.second << " ]";
}

template<class Ch, class Tr, class Tuple, int N>
struct TuplePrint {
    static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {
        TuplePrint<Ch, Tr, Tuple, N - 1>::print(os, t);
        os << std::get<N - 1>(t) << " ";
    }
};

template<class Ch, class Tr, class Tuple>
struct TuplePrint<Ch, Tr, Tuple, 0> {
    static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {}
};

template<class Ch, class Tr, class... Args>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr> &os,
                tuple<Args...> const &t) {
    os << "[ ";
    TuplePrint<Ch, Tr, tuple<Args...>, sizeof...(Args)>::print(os, t);
    return os << "]";
}


ll constexpr INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (auto i : range(n)) cin >> a[i] >> b[i] >> c[i];
    auto g = vec(n, 0, 0);
    for (auto i : range(n - 1)) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    vector<char> mark(n, false);
    ll ans = 0;
    using info = tuple<int, int, int>; // t1, t0, disp
    auto &&dfs = [&](auto &F, int v, ll mn) -> info {
        mark[v] = true;
        info res = {0, 0, 0};
        if (b[v] != c[v]) {
            get<2>(res)++;
            if (b[v]) get<0>(res)++;
            else get<1>(res)++;
        }
        for (auto &u : g[v]) {
            if (!mark[u]) {
                info ret = F(F, u, min(mn, a[v]));
                get<0>(res) += get<0>(ret);
                get<1>(res) += get<1>(ret);
                get<2>(res) += get<2>(ret);
            }
        }
        if (a[v] < mn) {
//            cerr << v + 1 << ' ' << res << '\n';
            int can = 2 * min(get<0>(res), get<1>(res));
            ans += can * a[v];
            get<0>(res) -= can / 2;
            get<1>(res) -= can / 2;
            return res;
        }
        return res;
    };
    info ret = dfs(dfs, 0, INF);
    if (get<0>(ret) != get<1>(ret)) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}
