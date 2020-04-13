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

    int n;
    cin >> n;
    vector<int> in(n), mark(n, false);
    rep (0, n, i) cin >> in[i];
    rep (0, 2, i) mark[i] = true;
    rep (2, n, i) {
        if (in[i] == in[i - 1] + in[i - 2]) {
            mark[i] = true;
        }
    }
    int best = 0, len = 0;
    rep (2, n, i) {
        if (mark[i]) len++;
        else {
            best = max(best, len);
            len = 0;
        }
    }
    best = max(len, best);
    best += 2;
    if (best > n) cout << n;
    else cout << best;
    return 0;
}