#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        int mn = 100000000;
        for (int i = 1; i < n; i++) {
            mn = min(mn, a[i] - a[i - 1]);
        }
        cout << mn << '\n';
    }
    return 0;
}