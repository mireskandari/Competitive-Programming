#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto R_ = [] { 
    return ios::sync_with_stdio(false), cin.tie(nullptr); 
}();

const int a[] = {6, 10, 14, 15, 21, 22};
constexpr int N = 6;

signed main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < N; ++i) 
            for (int j = i + 1; j < N; ++j) 
                for (int x = j + 1; x < N; ++x)
                    if (n - a[i] - a[j] - a[x] > 0 && find(a, a + N, n - a[i] - a[j] - a[x]) == a + N) {
                        printf("YES\n%d %d %d %d\n", a[i], a[j], a[x], n - a[i] - a[j] - a[x]);
                        goto found;
                    }
        puts("NO");
found:;
    }
    return 0;
}
