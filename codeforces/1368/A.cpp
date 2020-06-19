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
        long long a, b, n;
        cin >> a >> b >> n;
        int i = 0;
        while (a <= n && b <= n) {
            if (a > b) swap(a, b);
            a += b;
            i++;
        }
        cout << i << '\n';
    }
    return 0;
}