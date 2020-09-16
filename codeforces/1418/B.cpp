#include <bits/stdc++.h>
#define dbg(a) 0
// #define dbg(a) cerr << "\"" << #a << "\":" << a << '\n'
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        vector<int> l(n);
        for (auto &i : l) cin >> i;
        vector<int> b;
        b.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (l[i] == 0) {
                b.emplace_back(a[i]);
            }
        }
        sort(b.rbegin(), b.rend());
        for (int i = 0, j = 0; i < n; ++i) {
            if (l[i] == 0) {
                a[i] = b[j++];
            }
        }
        for (auto &i : a) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
