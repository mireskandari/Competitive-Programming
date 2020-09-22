#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto R_ = [] { 
    return ios::sync_with_stdio(false), cin.tie(nullptr); 
}();

constexpr int N = 1e5 + 10;

char s[N];

signed main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        memset(s, 0, sizeof(s));
        int i;
        for (i = 0; i < (n + 3) / 4; ++i) s[i] = '8';
        for (; i < n; ++i) s[i] = '9';
        reverse(s, s + n);
        printf("%s\n", s);
    }
    return 0;
}
