#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;

int n, t;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> t;
    if((t == 10 && n < 2)) {
        cout << -1;
        return 0;
    }
    if(t != 10) forn(0, n, i) cout << t;
    else {
        cout << 1;
        forn(0, n - 1, i) cout << 0;
    }
    return 0;
}