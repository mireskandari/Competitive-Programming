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
    int mn = *min_element(a.begin(), a.end());
    vector<int> id;
    for (int i = 0; i < n; i++) {
        if (a[i] == mn) id.emplace_back(i);
    }
    int mnd = INT_MAX;
    for (int i = 1; i < size(id); i++) {
        mnd = min(mnd, id[i] - id[i - 1]);
    }
    cout << mnd;
    return 0;
}