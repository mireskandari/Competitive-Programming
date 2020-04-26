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
    
    auto Solve = []() {
        ll n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        vector<ll> pref(n);
        pref[0] = s[0] == '0' ? 1 : -1;
        rep (1, n, i) {
            pref[i] = pref[i - 1] + (s[i] == '0' ? 1 : -1);
        }
        if (pref.back() == 0 && find(all(pref), x) != pref.end()) return cout << "-1\n", 0;
        ll cnt;
        cnt = x == 0;
        rep (0, n, i) {
            if (x != pref[i] && pref.back() != 0) {
                cnt += ((x - pref[i]) < 0 == (pref.back() < 0)) && (x - pref[i]) % pref.back() == 0 ? 1 : 0;
            }
            cnt += pref[i] == x;
        }
        return cout << cnt << '\n', 0;
    };
    int tc;
    cin >> tc;
    while (tc--) {
        Solve();
    }
    return 0;
}