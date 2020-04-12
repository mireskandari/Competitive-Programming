#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5 + 20;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> in(n);
        rep (0, n, i) cin >> in[i];
        int mx = in[0], mxt = 0;
        rep (1, n, i) {
            mx = max(mx, in[i]);
            int diff = mx - in[i];
            if (diff != 0) mxt = max(32 - __builtin_clz(diff), mxt);
        }
        cout << mxt << '\n';

    }
    return 0;
}