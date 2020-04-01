#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int solve() {
    long double a, b, c;
    cin >> a >> b;

    if (a >= b) return cout << "YES\n", 0;
    int m = ceil(sqrt(b)) + 10;
    rep (1, m + 1, i) {
        if (ceil(b / (i + 1)) + i <= a) {
            return cout << "YES\n", 0;
        }
    }
    cout << "NO\n";
    return 0;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}