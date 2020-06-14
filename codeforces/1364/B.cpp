#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

using ll = long long;
using ld = long double;

#define reps(a, b, x, s) for (decay<decltype(b)>::type x = a; x < b; x += s)
#define pers(b, a, x, s) for (decay<decltype(b)>::type x = b; x >= a; x -= s)
#define rep(a, b, x) reps(a, b, x, 1)
#define per(b, a, x) pers(b, a, x, 1)
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

void run_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep (0, n, i) cin >> a[i];
    vector<pair<int, vector<int>>> seg;
    rep (0, n, i) {
        auto &&make_new = [&]() {
            seg.emplace_back(0, vector<int>(1, a[i]));
        };
        if (seg.empty()) make_new();
        else if (seg.back().X == 1) {
            if (seg.back().Y.back() < a[i]) seg.back().Y.emplace_back(a[i]);
            else make_new();
        } else if (seg.back().X == 2) {
            if (seg.back().Y.back() > a[i]) seg.back().Y.emplace_back(a[i]);
            else make_new();
        } else {
            seg.back().X = a[i] < seg.back().Y.back() ? 2 : 1;
            seg.back().Y.emplace_back(a[i]);
        }
    }
    vector<int> ans;
    for (auto &p : seg) {
        ans.emplace_back(p.Y.front());
        if (size(p.Y) > 1) ans.emplace_back(p.Y.back());
        if (size(ans) >= 3) {
            if ((ans[ans.size() - 1] > ans[ans.size() - 2] && ans[ans.size() - 2] > ans[ans.size() - 3]) ||
                (ans[ans.size() - 1] < ans[ans.size() - 2] && ans[ans.size() - 2] < ans[ans.size() - 3])) {
                int temp = ans.back();
                ans.pop_back(); ans.pop_back();
                ans.emplace_back(temp);
            }
        }
    }
    cout << size(ans) << '\n';
    for (auto &i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}