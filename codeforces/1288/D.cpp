#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 3 * 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int in[N][8];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    rep (0, n, i) {
        rep (0, m, j) {
            cin >> in[i][j];
        }
    }

    function<pair<int, int>(int)> is = [&](int x) -> pair<int, int>{
        vector<int> mo(n, 0);
        vector<int> ison((1 << (m)), -1);
        rep (0, n, i) {
            rep (0, m, j) {
                if (in[i][j] >= x) {
                    mo[i] += (1 << j);
                }
            }
            ison[mo[i]] = i;
        }

        rep (0, n, i) {
//            cerr << bitset<8>(((1 << (m + 1)) - 1)) << '\n';
            rep (0, (1 << (m)), j) {
                if ((mo[i] | j) == ((1 << (m)) - 1)) {
//                    cerr << mo[i] << ' ' << j << '\n';
                    if (ison[j] != -1) return {ison[j], i};
                }
            }
        }
        return {-1, -1};
    };

    ll low = 0, high = 1e9;
    ll i, j, mid;
    while (true) {
//        cerr << low << ' ' << high << "\n\n\n\n";
        mid = (low + high) / 2;
        if (mid == low || mid == high) {
            break;
        }
        auto res = is(mid);
        if (res != make_pair(-1, -1)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    tie(i, j) = is(mid);
    auto res = is(high);
    if (res.X != -1) tie(i, j) = res;
    cout << i + 1 << ' ' << j + 1;
    return 0;
}