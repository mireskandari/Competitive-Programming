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
        if ((n / 2) & 1) cout << "NO\n";
        else {
            cout << "YES\n";
            ll sum = 0;
            for (int i = 2; i <= n; i += 2) {
                sum += i;
                cout << i << ' ';
            }
            int i = 1, a = 1;
            while (i < n / 2) {
                sum -= a;
                cout << a << ' ';
                a += 2;
                i++;
            }
            cout << sum << '\n';
        }
    }
    return 0;
}