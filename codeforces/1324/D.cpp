#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 2 * 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;
ll c1[N], c2[N], tmp[N], a[N], b[N];
ll solve(int l, int r) {
    if (r - l <= 1) return 0;
    int m = (r + l) / 2;
    ll res = solve(l, m) + solve(m, r);
    int i = l, j = m;
    while (i < m && j < r) {
        if (c1[i] > c2[j]) {
            j++;
            res += m - i;
        } else i++;
    }
    merge(c1 + l, c1 + m, c1 + m, c1 + r, tmp + l);
    rep (l, r, x) c1[x] = tmp[x];
    merge(c2 + l, c2 + m, c2 + m, c2 + r, tmp + l);
    rep (l, r, x) c2[x] = tmp[x];
    return res;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    rep (0, n, i) cin >> a[i];
    rep (0, n, i) cin >> b[i];
    rep (0, n, i) {
        c1[i] = a[i] - b[i];
        c2[i] = -c1[i];
    }
    cout << solve(0, n);
    return 0;
}