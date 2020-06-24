#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) a[i] = -a[i] - 1;
    }
    int cnt = 0;
    for (auto &i : a) if (i < 0) cnt++;
    if (cnt & 1) {
        auto p = min_element(a.begin(), a.end());
        *p = -(*p) - 1;
    }
    for (auto &j : a) cout << j << ' ';
    return 0;
}