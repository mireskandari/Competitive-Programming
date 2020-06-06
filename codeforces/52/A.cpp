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
    vector<int> a(n), cnt(4);
    for (auto &i : a) {
        cin >> i;
        cnt[i]++;
    }
    cout << n - *max_element(cnt.begin(), cnt.end());
    return 0;
}