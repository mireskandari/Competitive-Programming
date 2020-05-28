#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        int lasts = 1;
        if (k >= n) {
            cout << 1 << '\n';
            continue;
        }
        bool ok = false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (i <= k) lasts = i;
                if (i * i != n) {
                    if (n / i <= k) {
                        ok = true;
                        cout << i << '\n';
                    }
                }
            }
            if (ok) break;
        }
        if (!ok) cout << n / lasts << '\n';
    }
    return 0;
}