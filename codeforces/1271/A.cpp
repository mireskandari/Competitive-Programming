#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
//    cout << fixed << setprecision(15);
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long sum = 0;
    if (e > f) {
        sum += min(a, d) * e;
        d -= min(a, d);
        sum += min({b, c, d}) * f;
    } else {
        sum += min({b, c, d}) * f;
        d -= min({b, c, d});
        sum += min(a, d) * e;
    }
    cout << sum;
    return 0;
}