#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef string str;
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define forrn(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int m, s;
    cin >> m >> s;
    vector<int> mn, mx;
    mn.reserve(m);
    mx.reserve(m);
    if (s != 0) {
        int st = s;
        while (st > 0) {
            mx.push_back((st >= 9 ? 9 : st));
            st -= mx.back();
            // cout << st << '\n';
        }
        int ind = mx.size() - 1;
        while (mx.size() < m) {
            mx.push_back(0);
        }
        mn = mx;
        if (mn.back() == 0) {
            mn[mn.size() - 1] = 1;
            mn[ind]--;
        }
        reverse(all(mn));
        if (mn[0] == 0 || mn.size() != m) cout << -1;
        else forn (0, m, i) cout << mn[i];
        cout << ' ';
        if (mx[0] == 0 || mx.size() != m) cout << -1;
        else forn (0, m, i) cout << mx[i];
    } 
    else {
        if (m == 1) cout << "0 0";
        else cout << "-1 -1";
    }
    return 0;
}