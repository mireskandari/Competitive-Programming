#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll n;
    cin >> n;
    if(n == 1) cout << -1;
    else if(n % 2 != 0) {
        cout << fixed << (n * n - 1) / 2 << ' ' << (n * n + 1) / 2;
    }
    else {
        n /= 2;
        if(n == 1) cout << -1;
        else {
            cout << fixed << n * n - 1 << ' ' << n * n + 1;
        }
    }
    return 0;
}