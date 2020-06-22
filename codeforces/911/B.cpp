#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    int mx = -INT_MAX;
    for (int i = 1; i < n; i++) {
        int aa = a / i;
        int bb = b / (n - i);
        mx = max(mx, min(aa, bb));
    }
    cout << mx;
    return 0;
}