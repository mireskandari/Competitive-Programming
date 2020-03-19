#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {

        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "0\n";
            continue;
        }
        if (a > b) {
            cout << ((a - b) % 2 == 0 ? 1 : 2) << '\n';
        } else {
            cout << ((b - a) % 2 == 0 ? 2 : 1) << '\n';
        }
    }
    return 0;
}