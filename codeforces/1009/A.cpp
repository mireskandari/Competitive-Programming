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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), mark(m, false);
    rep (0, n, i) cin >> a[i];
    rep (0, m, i) cin >> b[i];
    int cnt = 0;
    rep (0, n, i) {
//        int best = INT_MAX, bi = -1;
        // cerr << i << ' ';
        int j = 0;
        while (j < m && mark[j]) j++;
        if (j >= m) break;
        if (b[j] >= a[i]) {
            cnt++;
            mark[j] = true;
        }

    }
    cout << cnt;
    return 0;
}