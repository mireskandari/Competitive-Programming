#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
        string mn;
        int mni;
        rep (0, n, i) {
            string pres = s.substr(0, i);
            if ((n - i) % 2 != 0) reverse(all(pres));
            string sss = s.substr(i) + pres;
            if (mn == "" || sss < mn) {
                mn = sss;
                mni = i;
            }
        }
        cout << mn << '\n' << mni + 1 << '\n';
    }
    return 0;
}