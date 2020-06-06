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
        int n, m, k;
        cin >> n >> m >> k;
        int win = min(m, n / k);
        int els = (m - win + k - 2) / (k - 1);
        cerr << win << ' ' << els << '\n';
        cout << win - els << '\n';
    }
    return 0;
}