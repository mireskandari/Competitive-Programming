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
        long long a, b;
        cin >> a >> b;
        long long fives = abs(a - b) / 5;
        long long rm = abs(a - b) % 5, ans;
        switch (rm) {
            case 0: ans = 0; break;
            case 1: ans = 1; break;
            case 2: ans = 1; break;
            case 3: ans = 2; break;
            case 4: ans = 2; break;
        }
        cout << fives + ans << '\n';
    }
    return 0;
}