#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll k, r, p;
    cin >> k >> r;
    for(p = 1;; p++) {
        if(k * p % 10ll == 0 || k * p % 10ll == r) {
            cout << p;
            return 0;
        }
    }
    return 0;
}