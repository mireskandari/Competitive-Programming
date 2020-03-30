#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

//int constexpr N = 1e5;
//int constexpr MOD = 1e9 + 7;
//int constexpr INF = 1e9;

int a[200000];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;

    rep (0, n, i) {
        cin >> a[i];
    }
    ll ans = 1;
    if (n <= m) {

        rep (0, n, i) {
            rep (i + 1, n, j) {
                ans = 1LL * ans * abs(a[i] - a[j]) % m;
            }
        }
    }
    else {
        ans = 0;
    }
    cout << ans % m;
    return 0;
}