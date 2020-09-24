#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e5 + 10;

int a[N], cnt[N];

signed main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++cnt[--a[i]];
        }
        int mx = *max_element(cnt, cnt + n);
        int c = count(cnt, cnt + n, mx);
        printf("%d\n", (c - 1) + (n - mx * c) / (mx - 1));
    }
    return 0;
}

