#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string cf = "codeforces";
    int k;
    cin >> k;
    vector<int> a(10, 1);
    int i = 0;
    int p = 1;
    while (p < k) {
        p = p / a[i] * (a[i] + 1);
        a[i]++;
        i = (i + 1) % 10;
    }
    for (int j = 0; j < 10; j++) {
        cout << string(a[j], cf[j]);
    }
    return 0;
}