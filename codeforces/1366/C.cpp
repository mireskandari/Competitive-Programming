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

// i think its getting better
// i hate A
void run_case() {
    int n, m;
    cin >> n >> m;
    vec<2, int> mp(n, m);
    rep (0, n, i) rep (0, m, j) cin >> mp[i][j];
    int dall = n + m - 2;
    vector<pair<int, int>> each(dall + 1);
    rep (0, n, i) {
        rep (0, m, j) {
            if (dall % 2 == 0 && (i + j) == dall / 2) continue;
            if (mp[i][j] == 0) each[i + j].X++;
            if (mp[i][j] == 1) each[i + j].Y++;
        }
    }
    ll cnt = 0;
    rep (0, dall + 1, i) {
        pair<int, int> al;
        al.X += each[i].X;
        al.X += each[dall - i].X;
        al.Y += each[i].Y;
        al.Y += each[dall - i].Y;
        cnt += min(al.X, al.Y);
    }
    cout << cnt / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}