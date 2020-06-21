#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

using ll = long long;
using ld = long double;

#define reps(a, b, x, s) for (decay<decltype((b))>::type x = (a); (x) < (b); (x) += (s))
#define pers(b, a, x, s) for (decay<decltype((b))>::type x = (b); (x) >= (a); (x) -= (s))
#define rep(a, b, x) for (decay<decltype((b))>::type x = (a); (x) < (b); ++(x))
#define per(b, a, x) for (decay<decltype((b))>::type x = (b); (x) >= (a); --(x))
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

template<int D, class T>
struct vec : public vector<vec<D - 1, T>> { template<class... Args> vec(int n = 0, Args... a) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {} };
template<class T> struct vec<1, T> : public vector<T> { vec(int n = 0, T const &val = T()) : vector<T>(n, val) {} };


template<int N, class T> void print_tuple(ostream &, T const &) { }
template<int N, class T, class H, class... Args> void print_tuple(ostream &os, T const &t) { if (N) os << " ,"; os << std::get<N>(t); print_tuple<N + 1, T, Args...>(os, t); }
template<class... Args> ostream &operator<<(ostream &os,const tuple<Args...> &t){ os << "{"; print_tuple<0, tuple<Args...>, Args...>(os, t); return os << "}"; }
template<class Ch, class Tr, class C> basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, C const &x) { os << "{ "; for (auto &y : x) os << y << " "; return os << "}"; }
template<class I, class J> ostream &operator<<(ostream &os, pair<I, J> const &p) { return os << "[ " << p.first << ", " << p.second << " ]"; }

// now start
ll const INF = 1e14;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    rep (0, n, i) cin >> a[i];
    auto &&solve = [&](int res) {
        bool ch = false;
        int sz = 0;
        rep (0, n, i) {
            if (!ch) {
                sz++;
                ch = !ch;
            } else {
                if (a[i] <= res) {
                    sz++;
                    ch = !ch;
                }
            }
        }
        int sz2 = 0;
        ch = true;
        rep (0, n, i) {
            if (!ch) {
                sz2++;
                ch = !ch;
            } else {
                if (a[i] <= res) {
                    sz2++;
                    ch = !ch;
                }
            }
        }
        return sz >= k || sz2 >= k;
    };
    ll l = 1, r = 1e9;
    rep (0, 50, i) {
        ll m = (l + r) >> 1;
        if (solve(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << (solve(l) ? l : r);
    return 0;
}