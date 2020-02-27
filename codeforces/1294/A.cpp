#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {

        int a, b, c, n;
        cin >> a >> b >> c >> n;
        long double m = a + b + c + n;
        m /= 3;
        cout << (a <= m && b <= m && c <= m && m == floor(m) ? "YES" : "NO") << '\n';
    }
    return 0;
}