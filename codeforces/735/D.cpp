#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (n & 1) {
                bool prime = true;
                for (long long j = 2; j * j <= n; j++) {
                    if ((n - 2) % j == 0) {
                        prime = false;
                        break;
                    }
                }
                cout << (prime ? 2 : 3);
            } else {
                cout << 2;
            }
            return 0;
        }
    }
    cout << 1;
    return 0;
}