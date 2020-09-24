#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e5 + 10;

int a[N], ans[N];

signed main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int p = 0;
    for (int i = 1; i < n; i += 2) ans[i] = a[p++];
    for (int i = 0; i < n; i += 2) ans[i] = a[p++];
    int cnt = 0;
    for (int i = 1; i < n - 1; ++i) cnt += ans[i] < ans[i - 1] && ans[i] < ans[i + 1];
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
    return 0;
}
