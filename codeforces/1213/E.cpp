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
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    auto &&check = [&](string a) {
        return (a != s && a != t);
    };

    auto &&check_all = [&](string ans) {
        bool correct = true;
        for (auto i : range<>(1, ans.size())) {
            if (!check(string(1, ans[i - 1]) + string(1, ans[i]))) {
                correct = false;
                break;
            }
        }
        if (correct) {
            cout << "YES\n" << ans;
            exit(0);
        }
    };

    string base = "abc";
    if (s[0] != s[1] && t[0] != t[1]) {
        do {
            string ans = string(n, base[0]);
            ans += string(n, base[1]);
            ans += string(n, base[2]);

            check_all(ans);

        } while (next_permutation(all(base)));

        cout << "NO";
        return 0;
    }

    do {
        string ans1, ans2;
        for (auto i : range<>(n)) ans1 += base;
        int par = 0;
        for (auto i : range<>(n)) {
            for (auto j : (par ? range<>(3) : rrange<>(2))) {
                ans2 += base[j];
            }
            par ^= 1;
        }

        check_all(ans1);
        check_all(ans2);

    } while (next_permutation(all(base)));

    cout << "NO";
    return 0;
}