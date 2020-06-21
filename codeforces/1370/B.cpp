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
    vector<int> a(2 * n);
    vector<pair<int, int>> odd, even;
    rep (0, 2 * n , i) {
        cin >> a[i];
        (a[i] & 1 ? odd : even).emplace_back(a[i], i);
    }
    if ((size(odd) & 1)) {
        even.pop_back();
        odd.pop_back();
    } else {
        if (size(odd) > size(even)) {
            odd.pop_back();
            odd.pop_back();
        } else {
            even.pop_back();
            even.pop_back();
        }
    }
    reps (0, (int)size(odd), i, 2) {
        cout << odd[i].Y + 1 << ' ' << odd[i + 1].Y + 1 << '\n';
    }
    reps (0, (int)size(even), i, 2) {
        cout << even[i].Y + 1 << ' ' << even[i + 1].Y + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}