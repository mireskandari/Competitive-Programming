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

int solve() {
    int n;
    cin >> n;
    vector<int> in(n), c(n), ccp(n), cp(n);
    iota(all(cp), 1);
    iota(all(ccp), 1);
    reverse(all(ccp));
    rep (0, n, i) cin >> in[i];
    rep (0, n, i) {
        c = in;
        rotate(c.begin(), c.begin() + i, c.end());
        if (c == ccp || c == cp) return cout << "YES\n", 0;
    }
    return cout << "NO\n", 0;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}