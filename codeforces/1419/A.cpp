#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
#define dbg(a) cout << __LINE__ << " \"" << #a << "\":" << a << '\n'

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        s = '0' + s;
        vector<ll> cnt0(2), cnt1(2);
        for (int i = 1; i <= n; i += 2) {
            cnt1[(s[i] - '0') % 2]++;
        }
        for (int i = 2; i <= n; i += 2) {
            cnt0[(s[i] - '0') % 2]++;
        }
        cout << (((n & 1) && cnt1[1]) || (!(n & 1) && !cnt0[0]) ? 1 : 2) << '\n';
    }
    return 0;
}
