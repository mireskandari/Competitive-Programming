#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        long long n;
        cin >> n;
        vector<int> a(n);
        long long sum = 0;
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        cout << (sum + n - 1) / n << '\n';
    }
    return 0;
}