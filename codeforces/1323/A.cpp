#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define rep(a, b, x) \
        for (decay<decltype(a, b)>::type x = a; x < b; x++)
#define repr(b, a, x) \
        for (decay<decltype(a, b)>::type x = b; x >= a; x--)

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n), odd;
        rep (0, n, i) cin >> a[i];
        bool found = false;
        rep (0, n, i) {
            if (a[i] & 1) odd.emplace_back(i);
            else {
                cout << 1 << '\n' << i + 1 << '\n';
                found = true;
                break;
            }
        }
        if (!found) {
            if (odd.size() > 1) {
                cout << 2 << '\n' << odd[0] + 1 << ' ' << odd[1] + 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}