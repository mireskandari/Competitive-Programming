#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;
        cout << pow(max(min(a, b) * 2, max(a, b)), 2) << '\n';
    }
    return 0;
}