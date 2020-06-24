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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (auto &i : w) cin >> i;
    vector<pair<int, int>> e(m);
    for (auto &i : e) {
        cin >> i.X >> i.Y;
        i.X--;
        i.Y--;
    }

    vector<int> cnt(n);
    vec<2, int> g(n);
    for (auto i : range<>(m)) {
        cnt[e[i].X]++;
        cnt[e[i].Y]++;
        g[e[i].X].emplace_back(i);
        g[e[i].Y].emplace_back(i);
    }

    vector<char> mark(n, false), markp(m, false);
    queue<int> q;
    for (auto i : range<>(n)) {
        if (cnt[i] <= w[i]) {
            q.emplace(i);
            mark[i] = true;
        }
    }
    if (q.empty()) {
        cout << "DEAD";
        return 0;
    }

    vector<int> ans;
    while (!q.empty()) {
        if ((int)ans.size() == m) break;
        int v = q.front();
        q.pop();
        for (auto &i : g[v]) {
            if ((int)ans.size() == m) break;
            if (markp[i]) continue;
            if (e[i].X != v) swap(e[i].X, e[i].Y);
            ans.emplace_back(i);
            markp[i] = true;
            cnt[e[i].Y]--;
            if (!mark[e[i].Y] && cnt[e[i].Y] <= w[e[i].Y]) {
                q.emplace(e[i].Y);
                mark[e[i].Y] = true;
            }
        }
    }

    if ((int)ans.size() < m) {
        cout << "DEAD";
        return 0;
    }
    cout << "ALIVE\n";
    for (auto i : rrange<>(m - 1)) {
        cout << ans[i] + 1 << ' ';
    }
    return 0;
}