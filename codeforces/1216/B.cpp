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
    vector<pair<int, int>> in(n);
    rep (0, n, i) {
        cin >> in[i].X;
        in[i].Y = i + 1;
    }
    sort(all(in), greater<>());
    ll cnt = 0;
    rep (0, n, i) cnt += in[i].X * i + 1;
    cout << cnt << '\n';
    rep (0, n, i) cout << in[i].Y << ' ';
    return 0;
}