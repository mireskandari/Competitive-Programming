#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define all(v) v.begin(),v.end()
#define X first
#define Y second

vector<string> fucking_keys = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char d;
    cin >> d;
    string s;
    cin >> s;
    d = d == 'R' ? -1 : 1;
    for (auto &c : s) {
        for (auto &v : fucking_keys) {
            auto p = find(all(v), c);
            if (p == v.end()) continue;
            c = v[p - v.begin() + d];
            break;
        }
    }
    cout << s;
    return 0;
}