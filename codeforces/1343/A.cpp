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
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin >> tc;
    auto Solve = []() {
        int n;
        cin >> n;
        rep (2, log2(n) + 2, i) {
            if (n % ((1 << i) - 1) == 0) return cout << n / ((1 << i) - 1) << '\n', 0;
        }
        return 0;
    };
    while (tc--) {
        Solve();
    }
    return 0;
}