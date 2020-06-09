#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string sss = s, ssss = s;
    sss.pop_back();
    ssss.pop_back();
    ssss.pop_back();
    ssss.push_back(s.back());
    cout << max({stoi(s), stoi(sss), stoi(ssss)});
    return 0;
}