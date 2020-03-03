#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

pair<int, int> d[1000];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int s, n;
    cin >> s >> n;
    forn(0, n, i) cin >> d[i].FV >> d[i].SV;
    sort(d, d + n);
    forn(0, n, i) {
        if(d[i].FV < s) {
            s += d[i].SV;
        } 
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}