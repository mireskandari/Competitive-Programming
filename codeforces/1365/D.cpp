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


ll constexpr INF = 1e14;

void run_case() {
    int n, m;
    cin >> n >> m;
    vec<2, char> mp(n, m);
    int cntb = 0, cntg = 0;
    for (auto &v : mp) {
        for (auto &i : v) {
            cin >> i;
            if (i == 'B') cntb++;
            if (i == 'G') cntg++;
        }
    }
    static int const dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    auto &&check = [&n, &m](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    vec<2, bool> can(n, m, false);
    auto &&dfs = [&](auto &f, int x, int y) -> void {
        if (mp[x][y] == '#') return;
        can[x][y] = true;
        for (auto i : range(4)) {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && !can[nx][ny]) f(f, nx, ny);
        }
    };
    if (cntb == 0) {
        dfs(dfs, n - 1, m - 1);
        for (auto i : range(n)) {
            for (auto j : range(m)) {
                if (mp[i][j] != 'G') continue;
                if (!can[i][j]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
        cout << "YES\n";
        return;
    }
    if (cntg == 0) {
        dfs(dfs, n - 1, m - 1);
        for (auto i : range(n)) {
            for (auto j : range(m)) {
                if (mp[i][j] == '#' && can[i][j]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
        cout << "YES\n";
        return;
    }
    for (auto i : range(n)) {
        for (auto j : range(m)) {
            if (mp[i][j] == 'B') {
                for (auto x : range(4)) {
                    int nx = i + dx[x], ny = j + dy[x];
                    if (check(nx, ny)) {
                        if (mp[nx][ny] == 'G') {
                            cout << "NO\n";
                            return;
                        }
                        if (mp[nx][ny] == '.') {
                            mp[nx][ny] = '#';
                        }
                    }
                }
            }
        }
    }
    can = vec<2, bool>(n, m, false);
    dfs(dfs, n - 1, m - 1);
    for (auto i : range(n)) {
        for (auto j : range(m)) {
            if (mp[i][j] == 'G' && !can[i][j]) {
                cout << "NO\n";
                return;
            }
            if (mp[i][j] == 'B' && can[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}

