#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(10);
    for (int i = 1; i < 10; i++) {
        cin >> a[i];
        a[i] += '0';
    }
    int i = 0;
    while (i < n && a[s[i] - '0'] <= s[i]) {
        i++;
    }
    s[i] = a[s[i] - '0'];
    i++;
    while (i < n && a[s[i] - '0'] >= s[i]) {
        s[i] = a[s[i] - '0'];
        i++;
    }
    cout << s;
    return 0;
}