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
    cin >> s;
    int cntl = count(s.begin(), s.end(), 'L'), cntr = count(s.begin(), s.end(), 'R');
    cout << (cntr + cntl + 1);
    return 0;
}