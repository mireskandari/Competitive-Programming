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



ll constexpr INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<ll> a;
    for (auto i : range(n)) {
        ll b; cin >> b;
        a.emplace(b);
    }
    map<ll, vector<ll>> g;
    for (auto &i : a) {
        g[i] = {};
        if (a.count(i * 2)) g[i].emplace_back(i * 2);
        if (i % 3 == 0 && a.count(i / 3)) g[i].emplace_back(i / 3);
    }
    map<ll, bool> mark;
    auto &&dfs = [&](auto &f, ll v) -> void {
        mark[v] = true;
        for (auto &u : g[v]) {
            if (!mark[u]) f(f, u);
        }
    };
    auto &&show = [&](auto &f, ll v) -> void {
        mark[v] = true;
        cout << v << ' ';
        for (auto &u : g[v]) {
            if (!mark[u]) {
                f(f, u);
            }
        }
    };
    for (auto &i : a) {
        mark = map<ll, bool>();
        dfs(dfs, i);
        bool ok = true;
        int cnt = 0;
        for (auto &p : mark) {
            if (!p.Y) {
                ok = false;
                break;
            }
            cnt++;
        }
        if (ok && cnt == n) {
            mark = map<ll, bool>();
            show(show, i);
            return 0;
        }
    }
    return 0;
}

