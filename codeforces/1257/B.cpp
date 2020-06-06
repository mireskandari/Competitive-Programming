#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        long long x, y;
        cin >> x >> y;
        if (x > y) cout << "YES\n";
        else {
            long long last = 1e18;
            while (x < y && x != last) {
                last = x;
                if (x & 1) x--;
                x *= 3;
                x /= 2;
            }
            if (x >= y) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}

