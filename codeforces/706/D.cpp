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

template<class C>
inline int constexpr __size(C c) { return c.size(); }
#define size __size

template<int D, class T>
struct vec : public vector<vec<D - 1, T>> {
    template<class... Args>
    vec(int n = 0, Args... a) :
    vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {}
};

template<typename T>
struct vec<1, T> : public vector<T> {
    vec(int n = 0, T const &val = T()) :
    vector<T>(n, val) {}
};
// now start

ll const INF = 1e14;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    multiset<int> t{0};
    while (q--) {
        char qt;
        cin >> qt;
        if (qt == '+') {
            int a;
            cin >> a;
            t.insert(a);
        }
        if (qt == '-') {
            int a;
            cin >> a;
            t.erase(t.find(a));
        }
        if (qt == '?') {
            int a;
            cin >> a;
            int sub = 0;
            per (30, 0, i) {
                sub += (~a) & (1 << i);
                auto p = t.lower_bound(sub);
                if (p == t.end() || ((*p) >> i) != (sub >> i)) {
                    sub ^= (1 << i);
                }
            }
            cout << (sub ^ a) << '\n';
        }
    }
    return 0;
}