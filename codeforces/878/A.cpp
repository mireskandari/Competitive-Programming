#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto R_ = [] { 
    return ios::sync_with_stdio(false), cin.tie(nullptr); 
}();

constexpr int LG = 10;

int change[LG];

signed main() {
    int n;
    scanf("%d", &n);
    fill(change, change + LG, 10);
    for (int i = 0; i < n; ++i) {
        char c;
        int x;
        scanf(" %c %d", &c, &x);
        if (c == '|') for (int i = 0; i < LG; ++i) if ((x >> i) & 1) change[i] = 1; // change all to 1
        if (c == '&') for (int i = 0; i < LG; ++i) if (!((x >> i) & 1)) change[i] = 0; // change all to 0
        if (c == '^') for (int i = 0; i < LG; ++i) if ((x >> i) & 1) change[i] ^= 1;
    }
    int and_ = 0, or_ = 0, xor_ = 0;
    for (int i = 0; i < LG; ++i) {
        if (change[i] == 0) and_ |= 1 << i;
        if (change[i] == 1) or_ |= 1 << i;
        if (change[i] == 11) xor_ |= 1 << i;
    }
    printf("3\n| %d\n& %d\n^ %d", or_, 1023 ^ and_, xor_);
    return 0;
}
