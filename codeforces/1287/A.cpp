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
        cin >> n;
        string s;
        cin >> s;
        ll cnt = 0;
        bool change = true;
        while (change) {
            change = false;
            string ss = s;
            rep (1, n, i) {
                if (s[i - 1] == 'A' && s[i] == 'P') {
                    ss[i] = 'A';
                    change = true;
                }
            }
            if (change) cnt++;
            s = ss;
        }
//        cout << s << '\n';
        cout << cnt << '\n';
    }
    return 0;
}