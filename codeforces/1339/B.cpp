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
        vector<int> in(n);
        rep (0, n, i) cin >> in[i];
        sort(all(in));
        vector<int> res;
        int l = 0, r = n - 1;
        while (l < r) {
            res.push_back(in[l++]);
            res.push_back(in[r--]);
        }
        if (n & 1) res.push_back(in[l]);
        reverse(all(res));
        rep (0, n, i) cout << res[i] << ' ';
        cout << '\n';
    }
    return 0;
}//
// Created by mrskndri on 4/12/20.
//

