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
        int n, a, b;
        cin >> n >> a >> b;
        string chars(b, 'a');
        iota(all(chars), 'a');
        string res;
        while (res.size() + b <= n) {
            res += chars;
        }
        if (res.size() < n) {
            int i = 0;
            while (res.size() < n) {
                res += chars[i];
                i++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}