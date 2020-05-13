#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        long long n, k;
        cin >> n >> k;
        long long s;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                s = i;
                break;
            }
        }
        cout << (n & 1 ? n + s + (k - 1) * 2 : n + k * 2) << '\n';
    }
    return 0;
}