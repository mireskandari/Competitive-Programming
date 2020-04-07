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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep (0, n, i) cin >> a[i];
        if (int mx = *max_element(all(a)), mn = *min_element(all(a)); mx - mn > 2 * k) cout << "-1\n";
        else {
            cout << mn + k << '\n';
        }
    }
    return 0;
}