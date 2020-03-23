#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    long long x, s, a;
    cin >> x >> s;
    if (s < x || ((s ^ x) & 1)) return cout << -1, 0;
    if (s == x && s == 0) return cout << 0, 0;
    if (s == x) return cout << "1\n" << s, 0;
    a = (s - x) >> 1;
    long long c1, c2, d1, d2, d3;
    c1 = x + a;
    c2 = a;
    if ((c1 ^ c2) == x && c1 + c2 == s) cout << "2\n" << c1 << ' ' << c2;
    else cout << "3\n" << x << ' ' << a << ' ' << a;
    return 0;
}