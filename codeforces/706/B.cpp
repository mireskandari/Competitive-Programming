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

    int n, q;
    cin >> n;
    vector<int> in(n);
    rep (0, n, i) cin >> in[i];
    cin >> q;
    vector<int> m(q);
    rep (0, q, i) cin >> m[i];
    sort(all(in));
    rep (0, q, i) {
//        ans[i] = ;
        cout << upper_bound(all(in), m[i]) - in.begin() << '\n';
    }

    return 0;
}