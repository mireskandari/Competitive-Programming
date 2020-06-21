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

void run_case(vector<int> &spf) {
    ll n;
    cin >> n;
    ll mx = -INT_MAX;
    rep (1, n + 1, i) {
        mx = max(mx, i / spf[i]);
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> spf(1e6 + 1);
    spf[1] = 1;
    rep (2, (int)1e6 + 1, i) {
        if (spf[i] == 0) {
            spf[i] = i;
            reps (2 * i, (int) 1e6 + 1, j, i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    int tc;
    cin >> tc;
    while (tc--) run_case(spf);
    return 0;
}