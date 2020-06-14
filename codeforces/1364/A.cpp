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


// now start
ll const INF = 1e14;

void run_case() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep (0, n, i) cin >> a[i];
    if (all_of(all(a), [&x](int b) { return b % x == 0; })) {
        cout << -1 << '\n';
        return;
    }
    if (accumulate(all(a), 0LL) % x != 0) {
        cout << n << '\n';
        return;
    }
    ll l = 0, r = n - 1;
    while (l < n && a[l] % x == 0) l++;
    while (r >= 0 && a[r] % x == 0) r--;
    cerr << n << ' ' << x << ' ' << l << ' ' << r << '\n';
    cout << max(n - l - 1, r) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}