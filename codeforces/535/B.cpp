#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    long long sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += (1LL << (s.size() - i - 1)) * (s[i] == '4' ? 1 : 2);
    }
    cout << sum;
    return 0;
}