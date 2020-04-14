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
        auto in = new vector<int>[26];
        rep (0, n, i) {
            int a;
            cin >> a;
            in[--a].push_back(i);
        }
        int mx = 0;
        rep (0, 26, x) {
            rep (0, in[x].size(), i) {
                rep (i + 1, in[x].size(), j) {
                    int match_size = 2 * min((int)in[x].size() - j, i + 1);
                    int best_mid = 0;
                    rep (0, 26, y) {
                        if (y == x) continue;
                        best_mid = max(best_mid,
                                       int(lower_bound(all(in[y]), in[x][j]) - lower_bound(all(in[y]), in[x][i])));
                    }
                    mx = max(mx, match_size + best_mid);
                }
            }
        }
        rep (0, 26, i) {
            mx = max((int)in[i].size(), mx);
        }
        cout << mx << '\n';
    }
    return 0;
}