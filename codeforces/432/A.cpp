#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int in[2000];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    forn(0, n, i) cin >> in[i];
    sort(in, in + n);
    int t = 0;
    for(int i = 0; i < n; i += 3) {
        forn(0, 3, j) {
            if(i + j >= n || in[i + j] + k > 5) break;
            if(j == 2) t++;
        }
    }
    cout << t;
    return 0;
}