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
    auto Solve = []() {
        int n;
        cin >> n;
        vector<pair<int, int>> in(n);
        rep (0, n, i) cin >> in[i].X >> in[i].Y;
        int lastp = in[0].X, lastc = in[0].Y;
        if (lastp < lastc) return cout << "NO\n", 0;
        rep (1, n, i) {
            int diffp = in[i].X - lastp;
            if (in[i].Y - lastc > diffp) return cout << "NO\n", 0;
            if (diffp < 0) return cout << "NO\n", 0;
            if (in[i].Y - lastc < 0) return cout << "NO\n", 0;
            lastp = in[i].X, lastc = in[i].Y;
        }
        cout << "YES\n";
        return 0;
    };
    while (tc--) {
        Solve();
    }
    return 0;
}