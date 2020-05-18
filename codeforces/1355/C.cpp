#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto NCr2 = [](long long n) -> long long {
        if (n < 2) return 0;
        return (n * (n - 1)) / 2;
    };
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long cnt = 0;
    for (int i = c; i <= d; i++) {
        long long ans = 0;
        ans = (b - a + 1) * (c - b + 1);
        ans -= (NCr2(i - a - b + 2) - NCr2(i - 2 * b - 1 + 2) - NCr2(i - a - c - 1 + 2) + NCr2(i - b - c - 2 + 2));
        cnt += ans;
    }
    cout << cnt;
    return 0;
}