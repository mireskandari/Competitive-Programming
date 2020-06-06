#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, ss;
    cin >> s;
    for (auto &c : s) {
        if (c == '/') {
            if (ss.empty() || ss.back() != '/') {
                ss += c;
            }
        } else ss += c;
    }
    if (ss.size() > 1 && ss.back() == '/') ss.pop_back();
    cout << ss;
    return 0;
}