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
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        if ((n * (a + b)) >= c - d && (n * (a - b)) <= c + d) cout << "Yes\n";
//        else if ( && (n * (a + b)) >= c + d) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}