#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

void run_case() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    int f = 0, s = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        (a[i] == 1 ? f : s)++;
    }
    vector<int> diffr(n + 1);
    for (int i = n + 1; i <= 2 * n; i++) {
        diffr[i - n] = diffr[i - n - 1] + (a[i] == 1 ? 1 : -1);
    }
    map<int, int> mp;
    for (int i = 0; i <= n; i++) {
        if (!mp.count(diffr[i])) mp[diffr[i]] = i;
    }
    int diff = f - s;
    int mn = INT_MAX;
    int cnt = 0;
    int diffl = 0;
    for (int i = n; i >= 0; i--) {
        int res = diff - diffl;
        if (mp.count(res)) mn = min(mn, cnt + mp[res]);
        if (i == 0) break;
        cnt++;
        diffl += (a[i] == 1 ? 1 : -1);
    }
    cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}