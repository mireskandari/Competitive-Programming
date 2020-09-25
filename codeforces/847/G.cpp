#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] { 
    return ios::sync_with_stdio(false), cin.tie(nullptr); 
}();

constexpr int N = 1010;

char s[N][10];

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int mx = 0;
    for (int i = 0; i < 7; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            cnt += int(s[j][i] == '1');
        mx = max(mx, cnt);
    }
    cout << mx;
    return 0;
}
