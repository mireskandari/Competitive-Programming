#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        if (n & 1) {
            cout << m * (n / 2) + (m + 1) / 2 << '\n';
        } else {
            cout << m * (n / 2) << '\n';
        }
    }
    return 0;
}