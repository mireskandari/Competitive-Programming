#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

using ll = long long;
using ld = long double;

#define reps(a, b, x, s) \
        for (decay<decltype(b)>::type x = a; x < b; x += s)
#define pers(b, a, x, s) \
        for (decay<decltype(b)>::type x = b; x >= a; x -= s)

#define rep(a, b, x) reps(a, b, x, 1)
#define per(b, a, x) pers(b, a, x, 1)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

template <class C>
inline int constexpr __size(C c) { return c.size(); }
#define size __size

template <int D, class T>
struct vec : public vector<vec<D - 1, T>> {
    template <class... Args>
    vec(int n = 0, Args... a) :
            vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {}
};

template <typename T>
struct vec<1, T> : public vector<T> {
    vec(int n = 0, T const &val = T()) :
            vector<T>(n, val) {}
};
// now start

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
struct Tp {
    static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {
        Tp<Ch, Tr, Tuple, N - 1>::print(os, t);
        os << std::get<N - 1>(t) << " ";
    }
};

template<class Ch, class Tr, class Tuple>
struct Tp<Ch, Tr, Tuple, 0> {
    static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {}
};

template<class Ch, class Tr, class... Args>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr> &os,
                tuple<Args...> const &t) {
    os << "[ ";
    Tp<Ch, Tr, tuple<Args...>, sizeof...(Args)>::print(os, t);
    return os << "]";
}

ll const INF = 1e14;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    int N = *max_element(all(a));
    vector<int> spf(N + 1, 0);
    spf[1] = 1;
    rep (2, N + 1, i) {
        if (spf[i] == 0) {
            spf[i] = i;
            reps (2 * i, N + 1, j, i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    vector<pair<int, int>> ready(N + 1, {-1, -1});
    vector<int> d1(n), d2(n);
    rep (0, n, i) {
        if (ready[a[i]].X != -1) {
            tie(d1[i], d2[i]) = ready[i];
        }
        int temp = a[i], firstd = 1;
        while (a[i] > 1) {
            firstd *= spf[a[i]];
            int secondd = temp / firstd;
            a[i] /= spf[a[i]];
            if (firstd == 1 || secondd == 1) continue;
            if (__gcd(firstd + secondd, temp) == 1) {
                ready[temp] = {firstd, secondd};
                tie(d1[i], d2[i]) = ready[temp];
                break;
            }
        }
    }
    rep (0, n, i) cout << (d1[i] == 0 ? -1 : d1[i]) << ' ';
    cout << '\n';
    rep (0, n, i) cout << (d2[i] == 0 ? -1 : d2[i]) << ' ';
    return 0;
}