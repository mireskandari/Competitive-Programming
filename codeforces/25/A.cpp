#include <bits/stdc++.h>

using namespace std;
int a[1000];
int main() {
    int n;
    scanf("%d", &n);
    int cntp = 0, cntnp = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        (a[i] & 1 ? cntnp : cntp)++;
    }
    if (cntnp == 1) {
        printf("%ld", find_if(a, a + n, [](int a) { return a & 1; }) - a + 1);
    } else {
        printf("%ld", find_if(a, a + n, [](int a) { return !(a & 1); }) - a + 1);
    }
    return 0;
}