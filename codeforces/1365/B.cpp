#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        if (int c = count(all(b), 0); c == n || c == 0) {
            vector<int> tmp(all(a));
            sort(all(tmp));
            if (tmp == a) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}