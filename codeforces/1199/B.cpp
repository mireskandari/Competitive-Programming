#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(15);
    long double h, l;
    cin >> h >> l;
    long double ans = ((l * l) - (h * h)) / (2.0 * h);
    cout << ans;
    return 0;
}