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

// AND AGAIN.
// for one fucking wrong cmp operator
void run_case() {
    int a, b;
    cin >> a >> b;
    if (b > a) swap(a, b);
    int f = min(a - b, b);
    a -= f * 2;
    b -= f;
    int d1 = a / 3;
    int rm1 = a % 3;
    int d2 = b / 3;
    int rm2 = b % 3;
    cerr << f << ' ' << d1 << ' ' << d2 << ' ' << rm1 << ' ' << rm2 << '\n';
    f += min(d1, d2) * 2;
    if (rm1 + rm2 >= 3) f++;
    cout << f << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}