#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int k, sum = 0, t = 0;
    vector<int> mons(12);
    cin >> k;
    forn (0, 12, i) cin >> mons[i];
    sort(all(mons), greater<int>());
    forn (0, 12, i) {
        if (sum >= k) {
            cout << t;
            return 0;
        }
        sum += mons[i];
        t++;
    }
    if (sum >= k) {
        cout << t;
        return 0;
    }
    cout << -1;
    return 0;
}