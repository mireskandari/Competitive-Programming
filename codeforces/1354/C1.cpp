#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(15);
    long double const PI = acos(-1);
    int tc;
    cin >> tc;
    while (tc--) {
        long double n;
        cin >> n;
        cout << (1.0 / tan(PI / (2.0 * n))) << '\n';
    }
    return 0;
}