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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> in(n);
    rep (0, n, i) cin >> in[i];
    vector<ll> a(m);
    rep (0, m, i) cin >> a[i];
    ll sum = 0;
    rep (0, m, i) {
        map<char, ll> cnt;
        rep (0, n, j) {
            cnt[in[j][i]]++;
        }
        char mx = 0;
        for (auto i : cnt) {
            if (mx == 0 || i.Y > cnt[mx]) mx = i.X;
        }
        sum += cnt[mx] * a[i];
    }
    cout << sum;
    return 0;
}