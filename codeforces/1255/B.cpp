#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        if (n == 2 || m < n) {
            cout << "-1\n";
            continue;
        }
        sort(a.begin(), a.end());
        long long c = 0;
        for (int i = 0; i < n; i++) {
            int ne = (i + 1) % n;
            c += a[i] + a[ne];
        }
        cout << c << '\n';
        for (int i = 0; i < n; i++) {
            int ne = (i + 1) >= n ? 0 : i + 1;
            cout << i + 1 << ' ' << ne + 1 << '\n';
        }
    }
    return 0;
}