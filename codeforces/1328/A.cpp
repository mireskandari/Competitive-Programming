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
        cout << (a % b == 0 ? 0 : b - a % b) << '\n';
    }
    return 0;
}