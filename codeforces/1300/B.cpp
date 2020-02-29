#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int in[200000];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {

        int n;
        cin >> n;
        n *= 2;
        forn(0, n, i) cin >> in[i];
        sort(in, in + n);
        cout << abs(in[n / 2] - in[n / 2 - 1]) << '\n';
    }
    return 0;
}