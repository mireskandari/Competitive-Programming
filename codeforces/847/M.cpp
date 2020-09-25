#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const auto IO_ = [] {
    return ios::sync_with_stdio(false), cin.tie(nullptr); 
}();

constexpr int N = 110;

int a[N], diff[N];

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) diff[i] = a[i] - a[i - 1];
    }
    if (int(set<int>(diff + 1, diff + n).size()) == 1)
        cout << a[n - 1] + diff[n - 1];
    else
        cout << a[n - 1];
    return 0;
}
