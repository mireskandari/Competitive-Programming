#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    long long i;
    for (i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            n -= i;
            i = 1e18;
            break;
        }
    }
    n /= 2;
    if (i != (long long)(1e18) && i * i > n) n = 0;
    cout << n + 1;
    return 0;
}