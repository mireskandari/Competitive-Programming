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
        long long a, b, k;
        cin >> a >> b >> k;
        if (k & 1) {
            cout << -(k / 2) * b + ((k + 1) / 2) * a << '\n';
        } else {
            cout << -(k / 2) * b + (k / 2) * a << '\n';
        }
    }
    return 0;
}