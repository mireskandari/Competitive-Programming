#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e6;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int x, y, n;
    cin >> x >> y >> n;

    int const ans[] = {-y + x, x, y, y - x, -x, -y};
    ll a = ans[n % 6] % MOD;
    cout << (a < 0 ? a + MOD : a);
    return 0;
}