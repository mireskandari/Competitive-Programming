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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int const N = 2e5 + 10;
    vector<int> cnt(N);
    for (auto i : range<>(n)) {
        int temp = a[i];
        while (temp > 0) {
            cnt[temp]++;
            temp /= 2;
        }
        cnt[0]++;
    }

    int best = INT_MAX;
    for (auto i : range<>(0, N)) {
        if (cnt[i] < k) continue;
        vector<int> t;
        for (auto j : range<>(n)) {
            int temp = a[j], c = 0;
            while (temp > 0) {
                if (temp == i) {
                    t.emplace_back(c);
                    break;
                }
                temp /= 2;
                c++;
            }
            if (i == 0) {
                t.emplace_back(c);
            }
        }

        sort(all(t));

        best = min(best, accumulate(t.begin(), t.begin() + k, 0));
    }

    cout << best;
    return 0;
}