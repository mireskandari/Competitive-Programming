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
        map<int, int> cnt;
        rep (0, n, i) {
            cin >> in[i];
            cnt[in[i]]++;
        }
        int mx = 0, mxcnt = 0;
        for (auto num : cnt) {
            if (num.Y > mxcnt) {
                mx = num.X;
                mxcnt = num.Y;
            }
        }
        int x;
        if (mxcnt - 1 >= cnt.size()) {
            x = cnt.size();
        }
        else {
            x = min(mxcnt, (int)cnt.size() - 1);
        }
        cout << x << '\n';
    }
    return 0;
}