#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    auto Solve = []() {
        long long n;
        cin >> n;
        long long cnt = 0;
        while (n != 1) {
            int rm2 = n % 2, rm3 = n % 3, rm5 = n % 5;
            if (rm2 == 0) {
                n >>= 1;
            } else if (rm3 == 0) {
                n = n * 2 / 3;
            } else if (rm5 == 0) {
                n = n * 4 / 5;
            } else {
                cout << -1 << '\n';
                return 0;
            }
            cnt++;
        }
        cout << cnt << '\n';
        return 0;
    };
    while (q--) {
        Solve();
    }
    return 0;
}