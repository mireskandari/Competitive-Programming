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
    vector<ll> in(n);
    vector<ll> ps(n), psr(n);
    rep (0, n, i) cin >> in[i];
    partial_sum(all(in), ps.begin());
    partial_sum(in.rbegin(), in.rend(), psr.begin());
    if (ps[n - 1] % 3 != 0) return cout << 0, 0;

    ll sum = ps[n - 1] / 3, cnt = 0;
    vector<int> cntsr(n, 0);
    cntsr[0] = psr[0] == sum ? 1 : 0;
    rep (1, n, i) cntsr[i] = cntsr[i - 1] + (psr[i] == sum ? 1 : 0);
    rep (0, n - 1, i) {
        if (ps[i] == sum) {
            cnt += cntsr[n - i - 2];
        }
    }
    rep (0, n - 1, i) {
        if (ps[i] == sum && ps[n - 1] - ps[i] == sum) cnt--;
    }
    cout << cnt;
    return 0;
}