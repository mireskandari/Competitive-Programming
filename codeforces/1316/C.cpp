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

    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    rep (0, n, i) cin >> a[i];
    rep (0, m, i) cin >> b[i];
    int i = 0;
    for (; i < n; i++) {
        if (__gcd(a[i], p) == 1) break;
    }
    int j = 0;
    for (; j < m; j++) {
        if (__gcd(b[j], p) == 1) break;
    }
    cout << i + j;
    return 0;
}