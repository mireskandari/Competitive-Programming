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
    vector<int> a(n), b(n), c(n);
    rep (0, n, i) cin >> a[i];
    rep (0, n, i) cin >> b[i];
    rep (0, n, i) c[i] = a[i] - b[i];
    sort(all(c));
    ll cnt = 0;
    rep (0, n, i) {
        if (c[i] <= 0) continue;
        cnt += i - (lower_bound(all(c), -c[i] + 1) - c.begin());
    }
    cout << cnt;
    return 0;
}