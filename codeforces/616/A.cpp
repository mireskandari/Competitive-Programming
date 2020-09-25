#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e6 + 10;

char a[N], b[N];

signed main() {
    scanf("%s %s", a, b);
    int n = strlen(a), m = strlen(b);
    reverse(a, a + n), reverse(b, b + m);
    while (n > 0 && a[n - 1] == '0') --n;
    while (m > 0 && b[m - 1] == '0') --m;
    reverse(a, a + n), reverse(b, b + m);
    if (n != m) {
        puts(n > m ? ">" : "<");
        exit(0);
    }
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) {
            puts(a[i] > b[i] ? ">" : "<");
            exit(0);
        }
    puts("=");
    return 0;
}



