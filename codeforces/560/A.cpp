#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int> in(n);
    forn (0, n, i) {
        cin >> in[i];
        if (in[i] == 1) {
            cout << -1;
            return 0;
        }
    }
    cout << 1;
    return 0;
}