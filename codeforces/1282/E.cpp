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

// magic
template<class T> struct Nit { T _v, _s; Nit(T v, T s) : _v(v), _s(s) {} operator T &() { return _v; } T operator *() const { return _v; } Nit &operator++() { _v += _s; return *this; } bool operator!=(Nit &a) { return (_s > 0 ? _v < a._v : _v >= a._v); } }; template<class T = int> struct range { T _b, _e, _s; range(T e) : _b(0), _e(e), _s(1) {} range(T b, T e, T s = 1) : _b(b), _e(e), _s(s) {} Nit<T> begin() { return Nit<T>(_b, _s); } Nit<T> end() { return Nit<T>(_e, _s); } }; template<class T = int> struct rrange : range<T> { rrange(T e, T b, T s = 1) : range<T>(e, b, -s) {} rrange(T e) : range<T>(e, 0, -1) {} }; template<class T> struct y_res { T t; y_res(T &&t) : t(forward<T>(t)) {} template<class... Args> decltype(auto) operator() (Args &&...args) const { return t(*this, forward<Args>(args)...); } }; template<class T> decltype(auto) y_comb(T &&t) { return y_res<decay_t<T>>(forward<T>(t)); } template<int D, class T> struct vec : public vector<vec<D - 1, T>> { template<class... Args> vec(int n = 0, Args... a) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {} }; template<class T> struct vec<1, T> : public vector<T> { vec(int n = 0, T const &val = T()) : vector<T>(n, val) {} };

template<int N, class T> void print_tuple(ostream &, T const &) {} template<int N, class T, class H, class... Args> void print_tuple(ostream &os, T const &t) { if (N) os << " ,"; os << std::get<N>(t); print_tuple<N + 1, T, Args...>(os, t); } template<class... Args> ostream &operator<<(ostream &os,const tuple<Args...> &t){ os << "{"; print_tuple<0, tuple<Args...>, Args...>(os, t); return os << "}"; } template<class Ch, class Tr, class C> basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, C const &x) { os << "{ "; for (auto &y : x) os << y << " "; return os << "}"; } template<class I, class J> ostream &operator<<(ostream &os, pair<I, J> const &p) { return os << "[ " << p.first << ", " << p.second << " ]"; }

// now start
ll constexpr INF = 1e14;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto &&run_case = []() {
        int n;
        cin >> n;

        using tri = array<int, 3>;
        using pii = pair<int, int>;

        vector<tri> a(n - 2);
        map<pii, int> cnt_side;
        for (auto &i : a) {
            cin >> i[0] >> i[1] >> i[2];
            pii f = {min(i[0], i[1]), max(i[0], i[1])};
            pii s = {min(i[2], i[1]), max(i[2], i[1])};
            pii t = {min(i[2], i[0]), max(i[2], i[0])};
            cnt_side[f]++;
            cnt_side[s]++;
            cnt_side[t]++;
        }

        vector<set<int>> con(n + 2);
        for (auto &p : cnt_side) {
            auto &f = p.X;
            auto &s = p.Y;
            if (s == 1) {
                con[f.X].insert(f.Y);
                con[f.Y].insert(f.X);
            }
        }

        vector<int> p, place(n + 1), place2(n + 1);
        vector<char> mark(n + 1, false);
        int now = 1;
        mark[now] = true;
        while ((int) p.size() < n) {
            auto f = (con[now].begin());
            if (mark[*f]) f = (prev(con[now].end()));
            mark[*f] = true;
            p.emplace_back(now);
            place[now] = (int) p.size() - 1;
//            place2[now] = (int) n - place[now] - 1;
            now = *f;
        }

        auto &&get_dist = [&](int i, int m) {
            int pre = (m - 1 + 3) % 3, nex = (m + 1) % 3;
            int p = place[a[i][pre]], mm = place[a[i][m]], nn = place[a[i][nex]];
            return min(abs(mm - p), abs(min(mm, p) + n - max(mm, p))) +
                    min(abs(mm - nn), abs(min(mm, nn) + n - max(mm, nn)));
        };

        vector<int> dist(n - 2);
        for (auto i : range<>(n - 2)) {
            dist[i] = min({get_dist(i, 0), get_dist(i, 1), get_dist(i, 2)});
        }

        cerr << dist << '\n';

        vector<int> ans(n - 2);
        iota(all(ans), 1);

        sort(all(ans), [&](auto &A, auto &B) {
            return dist[A - 1] < dist[B - 1];
        });

        for (auto &i : p) cout << i << ' ';
        cout << '\n';
        for (auto &i : ans) cout << i << ' ';
        cout << '\n';
    };

    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}