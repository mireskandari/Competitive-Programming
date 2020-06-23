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
    string s;
    for (int i = 1; (int)s.size() < n; i++) {
        s += to_string(i);
    }
    cout << s[n - 1];
    return 0;
}