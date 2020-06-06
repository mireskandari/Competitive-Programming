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
        if (abs(x - y) == 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}