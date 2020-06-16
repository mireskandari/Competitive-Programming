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


// now start
ll const INF = 1e14;

void run_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep (0, n, i) cin >> a[i];
    int cnto = 0, cnte = 0, disp = 0;
    rep (0, n, i) {
        (a[i] & 1 ? cnto : cnte)++;
        if ((a[i] & 1) != (i & 1)) disp++;
    }
    if (n & 1) {
        if (cnto != (n - 1) / 2) {
            cout << "-1\n";
            return;
        }
    } else {
        if (cnto != n / 2) {
            cout << "-1\n";
            return;
        }
    }
    cout << disp / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}