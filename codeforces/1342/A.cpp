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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (2 * a < b) {
            cout << (a * x) + (a * y) << '\n';
        } else {
            cout << b * min(x, y) + a * (max(x, y) - min(x, y)) << '\n';
        }
    }
    return 0;
}