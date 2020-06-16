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
    int n, k;
    cin >> n >> k;
    k++;
    string s;
    cin >> s;
    string ss = s;
    if (!count(all(s), '1')) {
        cout << (n + k - 1) / k << '\n';
    } else {
        int i = 0;
        while (i < n && s[i] == '0') i++;
        int j = i;
        while (j >= 0) {
            s[j] = '1';
            j -= k;
        }
        while (i < n) {
            int nx = i + 1;
            while (nx < n && s[nx] == '0') nx++;
            if (nx == n) {
                nx = INT_MAX;
            }
            while (i + k <= nx && i < n) {
                s[i] = '1';
                i += k;
            }
            i = nx;
        }
        cout << (count(all(s), '1') - count(all(ss), '1')) << '\n';
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