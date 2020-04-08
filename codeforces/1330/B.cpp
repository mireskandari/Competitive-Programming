#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)

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
        vector<int> in(n), cnt(n + 1, 0);
        deque<bool> can(n), rcan(n), cnmp(n + 1, false);
        rep (0, n, i) cin >> in[i];
        int now = 0;
        cnmp[0] = true;
        rep (0, n, i) {
            cnt[in[i]]++;
            cnmp[in[i]] = cnt[in[i]] == 1;
            while (now < n && cnmp[now]) now++;
            if (--now == i + 1) can[i] = true;
        }

        fill(all(cnt), 0);
        fill(1 + all(cnmp), false);
        now = 0;
        rep (0, n, i) {
            int ind = n - i - 1;
            cnt[in[ind]]++;
            cnmp[in[ind]] = cnt[in[ind]] == 1;
            while (now < n && cnmp[now]) now++;
            if (--now == i + 1) rcan[ind] = true;
        }
        int k = 0;
        vector<pair<int, int>> seg(n);
        rep (0, n - 1, i) {
            if (can[i] && rcan[i + 1]) seg[k++] = {i + 1, n - i - 1};
        }
        cout << k << '\n';
        rep (0, k, i) {
            cout << seg[i].X << ' ' << seg[i].Y << '\n';
        }
    }
    return 0;
}