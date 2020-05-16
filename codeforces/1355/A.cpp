#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    auto Mx = [](long long a) {
        long long mx = 0;
        while (a > 0) {
            mx = max(mx, a % 10);
            a /= 10;
        }
        return mx;
    };
    auto Min = [](long long a) {
        long long mx = 11;
        while (a > 0) {
            mx = min(mx, a % 10);
            a /= 10;
        }
        return mx;
    };
    while (tc--) {
        long long a, k, last = 0;
        cin >> a >> k;
        long long b = 1;
        if (k == 1) cout << a << '\n';
        else {
            while (b != k && a != last) {
                b++;
                last = a;
                a += Mx(a) * Min(a);
                cerr << a << '\n';
            }
            cout << a << '\n';
        }
    }
    return 0;
}