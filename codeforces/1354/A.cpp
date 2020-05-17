#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define int long long
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
//    cout << fixed << setprecision(15);
    int tc;
    cin >> tc;
    auto Solve = []() {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b >= a) return cout << b << '\n', 0;
        if (d >= c) return cout << "-1\n", 0;
        long double delta = a - b;
        cout << (int)(b + (ceil(delta / (long double)(c - d)) * c)) << '\n';
    };
    while (tc--) {
        Solve();
    }
    return 0;
}