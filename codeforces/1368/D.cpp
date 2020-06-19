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
    vector<bitset<30>> b(n);
    for (int i = 0; i < n; i++) b[i] = bitset<30>(a[i]);
    for (int i = 0; i < 30; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (b[j][i]) cnt++;
            b[j][i] = 0;
        }
        for (int j = 0; j < cnt; j++) {
            b[j][i] = 1;
        }
    }
    long long sum = 0;
    for (auto &i : b) sum += i.to_ullong() * i.to_ullong();
    cout << sum;
    return 0;
}