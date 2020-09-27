#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] {
    return ios::sync_with_stdio(false), cin.tie(nullptr);
}();

signed main() {
    ll A, B, n;
    cin >> A >> B >> n;
    if (B == 0) {
        cout << 0;
        exit(0);
    }
    if (A == 0) {
        cout << "No solution";
        exit(0);
    }
    if (B % A != 0) {
        cout << "No solution";
        exit(0);
    }
    for (ll i = -1000; i <= 1000; ++i) {
        ll res = 1;
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            res *= i;
            if (res > 1000) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        if (res == B / A) {
            cout << i;
            exit(0);
        }
    }
    cout << "No solution";
    return 0;
}
