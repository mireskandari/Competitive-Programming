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
    while (tc--) {
        int x, n, m;
        cin >> x >> n >> m;
        while (n > 0 && x > 10) {
            x = x / 2 + 10;
            n--;
        }
        while (m > 0) {
            x -= 10;
            m--;
        }
        cout << (x > 0 ? "NO\n" : "YES\n");
    }
    return 0;
}