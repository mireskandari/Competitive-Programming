#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long double n, x, y, xx, yy;
    cin >> n >> x >> y >> xx >> yy;
    auto Euclid = [](long double x1, long double x2,
            long double y1, long double y2) {
        return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
    };
    cout << ceil(Euclid(x, xx, y, yy) / (2.0 * n));
    return 0;
}