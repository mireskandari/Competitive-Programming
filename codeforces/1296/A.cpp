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

    int tc;
    cin >> tc;
    while(tc--) {

        int n;
        cin >> n;
        forn(0, n, i) cin >> in[i];
        int sum = accumulate(in, in + n, 0);
        if(sum % 2 == 0) {
            int c1 = count_if(in, in + n, [](int a) {
                return a % 2 == 1;
            });
            int c0 = n - c1;
            cout << (c0 > 0 && c1 > 0 ? "YES" : "NO") << '\n';
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}