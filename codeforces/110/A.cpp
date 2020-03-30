#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    long long n;
    cin >> n;
    while (n > 0) {
        if (n % 10 == 4 || n % 10 == 7) cnt++;
        n /= 10;
    }
    cout << (cnt == 4 || cnt == 7 ? "YES" : "NO");
    return 0;
}