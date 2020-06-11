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

ll const INF = 1e14;

// fucked up so bad :|
void run_case() {
    int n, x, m;
    cin >> n >> x >> m;
    vector<pair<int, int>> a(m);
    rep (0, m, i) cin >> a[i].X >> a[i].Y;
    int i = 0;
    while (i < m && (a[i].X > x || a[i].Y < x)) i++;
    if (i == m) {
        cout << 1 << '\n';
        return;
    }
    int l = a[i].X, r = a[i].Y;
    rep (i + 1, m, j) {
        if (a[j].Y >= l && a[j].Y <= r) {
            l = min(l, a[j].X);
        }
        if (a[j].X >= l && a[j].X <= r) {
            r = max(r, a[j].Y);
        }
        if (a[j].X <= l && a[j].Y >= r) {
            l = min(l, a[j].X);
            r = max(r, a[j].Y);
        }
    }
    cout << r - l + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}