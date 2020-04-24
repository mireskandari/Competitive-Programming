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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<ll> in(n);
        rep (0, n, i) cin >> in[i];
        vector<char> isp(n, false);
        ll mxi = 0, mx;
        ll cnt = 0;
        rep (0, k, i) {
            if (i == 0 || i == k - 1) continue;
            if (in[i] > in[i - 1] && in[i] > in[i + 1]) {
                isp[i] = true;
                cnt++;
            }
        }
        mx = cnt;
        rep (1, n - k + 1, i) {
            if (isp[i]) {
                cnt--;
            }
            ll last = in[i + k - 2];
            if (last > in[i + k - 3] && last > in[i + k - 1]) {
                cnt++;
                isp[i + k - 2] = true;
            }
            if (cnt > mx) {
                mx = cnt;
                mxi = i;
            }
        }
        cout << mx + 1 << ' ' << mxi + 1 << '\n';
    }
    return 0;
}