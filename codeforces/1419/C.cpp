#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e3 + 10;

int a[N];

signed main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n, x;
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        if (count(a, a + n, x) == n) {
            puts("0");
            continue;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += a[i] - x;
        puts(count(a, a + n, x) || sum == 0 ? "1" : "2");
    }
    return 0;
}
