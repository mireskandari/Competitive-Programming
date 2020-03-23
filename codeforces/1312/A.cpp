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
        if (a % b == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}